#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

void *fun()
{
  // critical sec
}

int main()
{	
	int rv;
	pthread_t a[3];
	for(int i=1; i<4; i++)
	{	
		//sleep(1);
		pthread_create(&a[i],NULL,fun,NULL);
		printf("thread %d\n",i);
	}
	for(int i=1; i<4; i++)
	{
		rv=pthread_join(&a[i],NULL);
		printf("thread %d returns %d\n",i,rv);
	}
return 0;
}
