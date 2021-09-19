#include "thread.h"
extern int synchronizedPrintf(const char *format,...);

class test1 : public Thread {
public:
	test1() : Thread(1024, 10){}
	~test1(){waitToComplete();}
	void run(){
		synchronizedPrintf("Test 1 started");
		runTest1();
		synchronizedPrintf("Test 1 ended");
	}
};

class test2 : public Thread {
public:
	test2() : Thread(1024, 10){}
	~test2(){waitToComplete();}
	void run(){
		synchronizedPrintf("Test 2 started");
		runTest2();
		synchronizedPrintf("Test 2 ended");
	}
};

class test3 : public Thread {
public:
	test3() : Thread(1024, 10){}
	~test3(){waitToComplete();}
	void run(){
		synchronizedPrintf("Test 3 started");
		runTest3();
		synchronizedPrintf("Test 3 ended");
	}
};

class test4 : public Thread {
public:
	test4() : Thread(1024, 10){}
	~test4(){waitToComplete();}
	void run(){
		synchronizedPrintf("Test 4 started");
		runTest4();
		synchronizedPrintf("Test 4 ended");
	}
};

class test5 : public Thread {
public:
	test5() : Thread(1024, 10){}
	~test5(){waitToComplete();}
	void run(){
		synchronizedPrintf("Test 5 started");
		runTest5();
		synchronizedPrintf("Test 5 ended");
	}
};

class test6 : public Thread {
public:
	test6() : Thread(1024, 10){}
	~test6(){waitToComplete();}
	void run(){
		synchronizedPrintf("Test 6 started");
		runTest6();
		synchronizedPrintf("Test 6 ended");
	}
};

class test7 : public Thread {
public:
	test7() : Thread(1024, 10){}
	~test7(){waitToComplete();}
	void run(){
		synchronizedPrintf("Test 7 started");
		runTest7();
		synchronizedPrintf("Test 7 ended");
	}
};

int userMain(int argc, char** argv){
	test1 t1;
	test2 t2;
	test3 t3;
	test4 t4;
	test5 t5;
	test6 t6;
	test7 t7;
	t1.start();
	t2.start();
	t3.start();
	t4.start();
	t5.start();
	t6.start();
	t7.start();

}
