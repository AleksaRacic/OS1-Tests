#include "thread.h"
extern int synchronizedPrintf(const char *format,...);
#include <iostream.h>
#include <stdlib.h>
#include "semaphor.h"

/*
 	 Test: Semafori sa spavanjem
*/

const int n = 1;
int t=-1;

Semaphore s(0);

class TestThread : public Thread
{
public:

	TestThread(): Thread(){}
	~TestThread()
	{
		waitToComplete();
	}
protected:

	void run();

};

void TestThread::run()
{
	t=0;
	s.wait(10);
	s.signal();
}

void tick()
{
	t++;
}

int runTest7()
{
	TestThread t[n];
	int i;
	for(i=0;i<n;i++)
	{
		t[i].start();
	}
	for(i=0;i<n;i++)
	{
		t[i].waitToComplete();
	}

	return 0;
}
