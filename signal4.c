#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<signal.h>
#include<wait.h>
void fun()
{
	printf("program can not be suspended\n");
}
int main()
{

	signal(SIGTSTP,fun);
	while(1)
	{
		sleep(1);
	}

}

