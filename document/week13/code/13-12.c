#include "my.h"

void *threadfun(void* arg){
	printf("new thread created, pid = [%5d]\n", getpid());
	return (void*) 0;
}
int main(int argc, char* argv[]){
	pthread_t tidp;
	int error;
	
	error = pthread_create(&tidp, NULL, threadfun, NULL);
	if (error != 0){
		perror("threadfun create failed !\n");
		return -1;
	}
	pthread_join(tidp, NULL);
	printf("Done!\n");
	return 0;
}














