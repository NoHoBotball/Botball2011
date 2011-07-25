#define CBC
//#include "lib.Definitions.h"
#define RunTime 30

void countdown();

int main()
{
	shut_down_in(30);
	countdown();
}


void countdown()
{
	float timeBegin = seconds();
	while (RunTime - (seconds() - timeBegin) > 20){}
	printf("Shut down in:\n");
	while(1)
	{
		printf("%2.0f\t", (RunTime - (seconds() - timeBegin)));
		sleep(0.950);
	}
}
