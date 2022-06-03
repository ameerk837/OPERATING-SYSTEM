#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
void *fun(void *x)
{
	int mul;
	mul = (int) x;
	for(int j=1;j<11;j++)
	{
		printf("%d X %d = %d\n",mul,j,j*mul);
	}
}
int main()
{
	pthread_t a[4];
	int mul=5;
	for(int i=0;i<4;i++)
	{
		pthread_create(&a[i],NULL,fun,(void*)mul);
		mul++;
	}
	for(int i=0;i<4;i++)
	{
		pthread_join(a[i],NULL);
	}
return 0;
}
