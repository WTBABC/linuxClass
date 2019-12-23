#include "my.h"

int c=100;
void* worker1(void*);
void* worker2(void*);

int main()
{
	int ret, i;
	
	pthread_t tid[2];
	ret = pthread_create(tid+0, NULL, worker1, NULL);
	if (ret != 0)
	{
		perror("worker1 create failed!\n");
		return -1;
	}
	ret = pthread_create(tid+1, NULL, worker2, NULL);
	if (ret != 0)
	{
		perror("worker2 create failed!\n");
		return -1;
	}
	
	for (i=0; i < 2; i++)
		pthread_join(tid[i], NULL);
	return 0; 
}
void* worker1(void* param)
{
	while (c > 0)
	{
		usleep(1000);
		printf("thread 1 sell ticket: %d\n", c--);
		//pthread_yield();
		//sched_yield();
	}
}
void* worker2(void* param)
{
	while (c > 0)
	{
		usleep(1000);
		printf("thread 2 sell ticket: %d\n", c--);
		//pthread_yield();
		//sched_yield();
	}
}

