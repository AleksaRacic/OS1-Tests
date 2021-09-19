
#include "thread.h"

extern int synchronizedPrintf(const char *format,...);

class TestThread : public Thread
{
public:

	TestThread(): Thread() {};
	~TestThread()
	{
		waitToComplete();
	}
protected:

	void run();

};

void TestThread::run()
{
	synchronizedPrintf("Thread %d: loop1 starts\n", getId());

	for(int i=0;i<32000;i++)
	{
		for (int j = 0; j < 32000; j++);
	}

	synchronizedPrintf("Thread %d: loop1 ends, dispatch\n",getId());

	dispatch();

	synchronizedPrintf("Thread %d: loop2 starts\n",getId());

	for (int k = 0; k < 20000; k++);

	synchronizedPrintf("Thread %d: loop2 ends\n",getId());


}

class WaitThread: public Thread
{
private:
	TestThread *t1_,*t2_;

public:
	WaitThread(TestThread *t1, TestThread *t2): Thread()
	{
		t1_ = t1;
		t2_ = t2;
	};

	~WaitThread()
		{
			waitToComplete();
		}

protected:

	void run()
	{
		synchronizedPrintf("Starting tests...\n");
		t1_->waitToComplete();
		synchronizedPrintf("Test 1 completed!\n");
		t2_->waitToComplete();
		synchronizedPrintf("Test 2 completed!\n");
	}
};

void tick() {}

int userMain(int argc, char** argv)
{
	synchronizedPrintf("User main starts\n");
	TestThread t1,t2;
	WaitThread w(&t1,&t2);
	t1.start();
	t2.start();
	w.start();
	synchronizedPrintf("User main ends\n");
	return 16;
}

