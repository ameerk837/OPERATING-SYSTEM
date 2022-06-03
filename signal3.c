#include<unistd.h>
#include<stdio.h>
#include<wait.h>
#include<signal.h>

void fun(int num)
{
	if(num==SIGINT)
		printf("sigint received\n");
	else if(num==SIGQUIT)
		printf("sigquit received\n");

}
int main()
{
	while(1)
	{
		signal(SIGINT,fun);
		signal(SIGQUIT,fun);
		sleep(1);
		printf("proccess running\n");
	}
}
