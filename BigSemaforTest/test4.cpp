#include "thread.h"
extern int synchronizedPrintf(const char *format,...);
#include <iostream.h>
#include <stdlib.h>
#include "semaphor.h"

/*
 	 Test: Semafori sa spavanjem 4
*/

int t=-1;

const int n=15;

Semaphore s(1);

class TestThread : public Thread
{
private:
	Time waitTime;

public:

	TestThread(Time WT): Thread(), waitTime(WT){}
	~TestThread()
	{
		waitToComplete();
	}
protected:

	void run();

};

void TestThread::run()
{
	int r = s.wait(waitTime);
	if(getId()%2)
		s.signal();
}

void tick()
{
	t++;
}

int runTest4()
{
	TestThread* t[n];
	int i;
	for(i=0;i<n;i++)
	{
		t[i] = new TestThread(5*(i+1));
		t[i]->start();
	}
	for(i=0;i<n;i++)
	{
		t[i]->waitToComplete();
	}
	delete t;
	return 0;
}
