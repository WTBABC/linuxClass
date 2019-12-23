#include "my.h"

int c=100;
pthread_mutex_t mutex;
pthread_cond_t ready = PTHREAD_COND_INITIALIZER;
void* worker1(void*);
void* worker2(void*);

int main()
{
	int ret, i;
	pthread_t tid[2];

	pthread_mutex_init(&mutex, NULL);	
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
	pthread_mutex_destroy(&mutex);
	return 0; 
}
void* worker1(void* param)
{
	int ret;
	pthread_mutex_lock(&mutex);
	while (c > 0)
	{
		if (c%2 == 0){
			usleep(1000);
			printf("thread 1 sell ticket: %d\n", c--);
			pthread_cond_signal(&ready);
		} 
		else {
			pthread_cond_wait(&ready, &mutex);
		}
		pthread_mutex_unlock(&mutex);
	}
}
void* worker2(void* param)
{
	int ret;
	pthread_mutex_lock(&mutex);
	while (c > 0)
	{
		if (c%2 == 1){
			usleep(1000);
			printf("thread 2 sell ticket: %d\n", c--);
			pthread_cond_signal(&ready);
		} 
		else {
			pthread_cond_wait(&ready, &mutex);
		}
		pthread_mutex_unlock(&mutex);
	}
}

