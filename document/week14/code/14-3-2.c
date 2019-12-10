#include "my.h"
#define NUM 8
void * fun(void * arg){
	int* in = (int*) arg;
	//printf("in = %d\n", *in);
	printf("hello from thread %d\n", *in);
	pthread_exit(NULL);
	return NULL;	
}
int main(){
	pthread_t tid[NUM];
	int ret, i;
	
	for (i=0; i < NUM; i++){
		printf("create thread %d\n", i);
		ret = pthread_create(tid+i, NULL, fun, (void*) &i);
		if (ret != 0){
			perror("create failed\n");
			return -1;
		}
	}
	pthread_exit(NULL);
}
