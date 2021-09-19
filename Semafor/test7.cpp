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
	synchronizedPrintf("Thread waits for 10 units of time...\n");
	t=0;
	s.wait(10);
	synchronizedPrintf("Thread finished.\n");
	s.signal();
}

void tick()
{
	t++;
	if(t)
		synchronizedPrintf("%d\n",t);
}

int userMain(int argc, char** argv)
{
	synchronizedPrintf("Test starts.\n");
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
	synchronizedPrintf("Test ends.\n");
	return 0;
}
