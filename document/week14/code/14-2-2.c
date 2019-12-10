#include "my.h"
#define NUM 4
void * fun(void *arg){
	int *pt, sum=0, begin, end, i;
	
	pt = (int*)arg;
	printf("%d thread : tid=%lx\n", (*pt), pthread_self());

	begin = (*pt)*100+1;
	end = begin + 100;	
	for (i=begin; i < end; i++)
		sum += i;	
	printf("%d thread : %d~%d:sum=%d\n", (*pt), begin, end, sum);
	return NULL;
}
int main() {
	pthread_t tid[NUM];
	int i, ret[NUM];
	
	for (i=0; i < NUM; i++){
		ret[i] = pthread_create(tid+i, NULL, fun, &i);
		if (ret[i] != 0){
			printf("thread create failed!\n");
			return -1;
		}
	}
	for (i=0; i < NUM; i++)
		pthread_join(tid[i], NULL);
	
	return 0;
}
