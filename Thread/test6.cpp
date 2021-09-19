#include "thread.h"

extern int synchronizedPrintf(const char *format,...);


/*
 	 Test: frekventni dispatch
*/

const int n = 10;

void tick(){}

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
	for(int i=0;i<32000;i++)
	{
		for(int j=0;j<16;j++){
		dispatch();
		synchronizedPrintf(".");
		}
	}
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
