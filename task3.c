#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

void *fun(void* x)
{
	int i= (int) x;
	printf("participant %d on day registration\n",i);
}
void *fun1(void *x)
{
	int i=(int) x;
	printf("participant %d announcement\n",i);
}
void *fun2(void *x)
{
	int i=(int) x;
	printf("participant %d sponsores\n",i);
}
int main()
{
	pthread_t a[10];
	int j;
	int k;
	printf("press 1 for reg, 2 for announcement and 3 for sponsores\n");
	scanf("%d\n",&j);
	for(int i=0;i<10;i++)
	{
		if(j==1)
		{
			pthread_create(a+i,NULL,fun,(void*)k);
			//k++;
		}
		else if(j==2)
		{
			pthread_create(a+i,NULL,fun1,(void*)k);
		//	k++;
		}
		else if(j==3)
		{
			pthread_create(a+i,NULL,fun2,(void*)k);
		//	k++;
		}
		else
			exit(0);
	}
return 0;
}
