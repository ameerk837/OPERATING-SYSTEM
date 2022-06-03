#include<unistd.h>
#include<stdio.h>
#include<wait.h>
#include<signal.h>

void fun()
{

	printf("interrupted as ctrl C was pressed\n");

}

int main()
{
	signal(SIGINT,fun);
	while(1)
	{	
		sleep(1);
		printf("proccess running\n");
	
	}
return 0;

}
