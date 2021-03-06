#include "thread.h"
#include <iostream.h>
#include <stdlib.h>
#include "semaphor.h"

/*
 	 Test: Semafori sa spavanjem 3
*/

Semaphore* mutex = 0;

class Znak : public Thread
{
public:
	Znak(char znak, int n) : Thread(), znak(znak), n(n) {}
	virtual ~Znak() { waitToComplete(); }

	void run()
	{
		for (long i = 0; i < 100000; i++)
		{
			if (mutex->wait(n)) {
				mutex->signal();
			}

		}

		if (mutex->wait(n)) {
			mutex->signal();
		}
	}

private:
	char znak;
	int n;

};

void tick(){

}

int runTest2() {
	mutex = new Semaphore(1);

	Znak* a = new Znak('a', 10);
	Znak* b = new Znak('b', 15);
	Znak* c = new Znak('c', 20);

	a->start();
	b->start();
	c->start();
	delete a;
	delete b;
	delete c;

	if (mutex->wait(1)) {
		mutex->signal();
	}

	delete mutex;


	return 0;
}
