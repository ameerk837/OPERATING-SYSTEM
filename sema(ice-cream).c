#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t icecream;

void *fun(void *x)
{	sem_wait(&icecream);
	sleep(1);
	int i=(int) x;
	printf("ice cream by person %d\n",i);
	sem_post(&icecream);
//	pthread_exit(0);
}
int main()
{
	pthread_t a[3];
	int mul=0;
	sem_init(&icecream,0,1);
	for(int i=0;i<3;i++)
	{
		pthread_create(a+i,NULL,fun,(void*)mul);
		mul++;
	}
	for(int i=0;i<3;i++)
	{
		pthread_join(a[i],NULL);
		mul++;
	}

	//sem_destroy(&icecream);
return 0;

}
 
