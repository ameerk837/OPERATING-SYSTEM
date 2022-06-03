#include<signal.h>
#include<stdlib.h>
#include<stdio.h>
#include<wait.h>
void fun()
{
	
	printf("sigint call\n");
}
void fun1()
{
	printf("sigquit call\n");
}
void fun2()
{
	printf("sigtstp call\n");
}
int main()
{
	signal(SIGQUIT,fun1);
	signal(SIGINT,fun);
	signal(SIGTSTP,fun2);
	while(1)
	{
		sleep(1);
		printf("proccess running\n");
	}
return 0;
}
