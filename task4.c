#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
#define N 2

int arr[5]={2,4,3,1};

void *fun(void *x)
{
	int i=(int) x;
	int sum=0;
	for(int j=0;j<5;j++)
	{
		sum+=arr[i+j];
	}
	printf("the sum = %d\n",sum);
}


int main()
{
int k=0,m=0;
pthread_t a[N];

for(int i=0;i<N;i++)
{
	pthread_create(a+i,NULL,fun,(void*)k);
}


for(int i=0; i<N; i++)
{
	pthread_join(a[i],NULL);
}



}
