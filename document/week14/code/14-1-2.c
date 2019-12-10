#include "my.h"
#include <sys/syscall.h>
void *worker(void* arg){
	int TID = syscall(SYS_gettid);
	printf("thread=%d, gettid return %d\n", TID, TID);
	printf("thread=%d, pthread_self return %p\n", TID, (void*)pthread_self());
	printf("thread=%d, exit\n", TID);
	pthread_exit(NULL);
	return NULL;
}
int main(){
	pthread_t tid = 0;
	int ret;

	ret = pthread_create(&tid, NULL, worker, NULL);
	//ret = pthread_join(tid, NULL);

	ret = pthread_create(&tid, NULL, worker, NULL);
	ret = pthread_join(tid, NULL);
	printf("finished\n");
	return 0;
}
