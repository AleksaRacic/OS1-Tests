/*
 * test.cpp
 *
 *  Created on: Aug 22, 2021
 *      Author: OS1
 */

#include "thread.h"
extern int synchronizedPrintf(const char *format,...);

int y = 0;

class runer : public Thread{
public:
	runer(int);
	void run();
};

runer::runer(int time):Thread(256, time){}

volatile int flag = 0;
volatile int count = 0;

void runer::run() {
	while(count<50){
		if(flag){
			synchronizedPrintf("Thread 1 running\n");
			flag = 0;
		}
	}
}

class runer1 : public Thread{
public:
	void run();
	runer1(int);
};

void runer1::run() {
	while(count<60){
		if(flag){
			synchronizedPrintf("Thread 2 running\n");
			flag = 0;
		}
	}
}
runer1::runer1(int time):Thread(256, time){}


void tick(){
	if(y>10){
		y=0;
		synchronizedPrintf("count: %d\n", count);
		count++;
		flag = 1;
	}
	y++;
}

int userMain(int argc, char **argv){
	runer* t = new runer(6);
	runer1* t1 = new runer1(4);
	t->start();
	t1->start();
	t->waitToComplete();
	t1->waitToComplete();
	return 0;
}



