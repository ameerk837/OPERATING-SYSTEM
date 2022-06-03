#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

sem_t mutex,mutex1,mutex2;

void *fun(void *x)
{
	sem_wait(&mutex);
	sleep(2);
	int i=(int) x;
	printf("passenger %d at weighing counter\n",i);
	sem_post(&mutex);
}

void *fun1(void *x)
{
	sem_wait(&mutex1);
	sleep(3);
	int i=(int) x;
	printf("passenger %d at check in counter\n",i);
	sem_post(&mutex1);
}

void *fun2(void *x)
{
	sem_wait(&mutex2);
	sleep(1);
	int i=(int) x;
	printf("passenger %d at boarding counter\n",i);
	sem_post(&mutex2);
}
int main()
{
	sem_init(&mutex,0,1);
	sem_init(&mutex1,0,1);
	sem_init(&mutex2,0,1);
	pthread_t a[10];
	int mul=0;
	for(int j=1;j<11;j++)
	{
		pthread_create(a+j,NULL,fun,(void*)mul);
		pthread_create(a+j,NULL,fun1,(void*)mul);
		pthread_create(a+j,NULL,fun2,(void*)mul);
		mul++;		
	}
	for(int j=1;j<11;j++)
	{
		pthread_join(a[j],NULL);
		pthread_join(a[j],NULL);
		pthread_join(a[j],NULL);
		mul++;
	}
	return 0;
	
}
