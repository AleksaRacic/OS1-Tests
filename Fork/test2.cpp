#include <iostream.h>
#include <stdlib.h>
#include <assert.h>

#include "thread.h"
#include "kernel.h"

int userMain(int argc, char* argv[])
{
	const int value = 5;
	int data = 0, *pData = &data;
	ID result = Thread::fork();
	if ( result != -1) {
		if (result == 0) {
			systemLock()
			cout<<"Child created!"<<endl;
			systemUnlock()
			*pData = value;
			data = value + 1;
			systemLock()
			cout<<"Child finished!"<<endl;
			systemUnlock()
			Thread::exit();
		} else {
			Thread::waitForForkChildren();
			assert(value == data);
		}
	}

	assert(result > 0);


	cout<<"userMain finished!"<<endl;
	systemUnlock()
	return 0;
}
