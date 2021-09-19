/*
	Test: brojac sekundi
*/


extern int synchronizedPrintf(const char *format,...);

unsigned t=18;
unsigned seconds = 5;



void secondPast()
{
	if(seconds)
		synchronizedPrintf("%d\n",seconds);
	seconds--;
}

void tick()
{
	t--;
	if(t==0){
		t = 18;
		secondPast();
	}
}



int userMain(int argc, char** argv)
{
	synchronizedPrintf("Starting test\n");
	while(seconds);
	synchronizedPrintf("Test ends\n");
	return 0;
}
