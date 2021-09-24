#include "thread.h"
#include "semaphor.h"
#include "event.h"

/*
	Test: dogadjaji
*/

#include <iostream.h>
#include <stdlib.h>

void synchronizedPrintf(const char *format, ...);

PREPAREENTRY(9,1);

Semaphore* mutex = 0;
Semaphore* sleepSem = 0;

void tick() {}


class Znak : public Thread
{
public:
	Znak(char znak, int n) : Thread(), znak(znak), n(n) {}
	virtual ~Znak() { waitToComplete(); }

	void run()
	{
		synchronizedPrintf("start %c\n", znak);
		mutex->signal();
		for (int i = 0; i < n; i++)
		{
			if (mutex->wait(1)) {
				synchronizedPrintf("%c", znak);
				mutex->signal();
			}


			Time sleepTime = 3 + rand() % 8;
			sleepSem->wait(sleepTime);

			// dispatch();
		}

		if (mutex->wait(1)) {
			synchronizedPrintf("%c finished\n", znak);
			mutex->signal();
		}
	}

private:
	char znak;
	int n;

};


class Key : public Thread {
public:
	Key(int n) : Thread(), n(n) {}
	virtual ~Key() { waitToComplete(); }

	void run() {
		Event e(9);
		for (int i = 0; i < n; i++) {
			if (mutex->wait(1)) {
				synchronizedPrintf("\nkeyWaiting %d\n", i+1);
				mutex->signal();
			}
			e.wait();

			if (mutex->wait(1)) {
				synchronizedPrintf("\nkeyContinue %d\n", i+1);
				mutex->signal();
			}

			sleepSem->wait(3);
		}

		if (mutex->wait(1)) {
			synchronizedPrintf("\nKeyFinished %d\n", i+1);
			mutex->signal();
		}
	}

private:
	int n;

};


int userMain(int argc, char* argv[]) {
	mutex = new Semaphore(1);
	sleepSem = new Semaphore(0);

	Znak* a = new Znak('a', 10);
	Znak* b = new Znak('b', 15);
	Znak* c = new Znak('c', 20);
	Key* k = new Key(50);

	a->start();
	b->start();
	c->start();
	k->start();

	delete a;
	delete b;
	delete c;
	delete k;

	if (mutex->wait(1)) {
		cout << endl << "userMain finished" << endl;
		mutex->signal();
	}

	delete sleepSem;
	delete mutex;

	return 0;
}
