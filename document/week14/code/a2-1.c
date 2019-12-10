#include "my.h"

int i=1;
void * fun(void* arg){
	i=9;
	printf("tid=%lx\n", pthread_self());
	printf("i=%d, &i=%p\n", i, &i);
	pthread_exit(&i);
}

int main(){
	int ret, *rv;
	pthread_t tid;
	
	ret = pthread_create(&tid, NULL, fun, NULL);
	if (ret != 0){
		perror("pthread create failed\n");
		return -1;
	}
	pthread_join(tid, (void**)&rv);
	printf("rv=%d, &rv=%p\n", *rv, rv);
	return 0;
}
