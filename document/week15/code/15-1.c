#include "my.h"

pthread_rwlock_t rwlock;
int g = 0;
void * fun(void* param){
	int i;
	pthread_rwlock_rdlock(&rwlock);	//读锁
	for (i=0; i < LOOP; i++){
		g++;
	}
	//printf("g = %d\n", g);
	pthread_rwlock_unlock(&rwlock);
	return NULL;
}
int main(){
	pthread_t tid[NUM];
	int i, ret;

	ret = pthread_rwlock_init(&rwlock, NULL);
	if (ret){
		perror("lock init failed!\n");
		return 1;
	}
	pthread_rwlock_wrlock(&rwlock);	//写锁
	for (i=0; i < NUM; i++){
		ret = pthread_create(&tid[i], NULL, fun, NULL);
		if (ret){
			perror("thread create failed!\n");
			return 2;
		}		
	}
	//printf("LOOP = %d\n", LOOP);
	pthread_rwlock_unlock(&rwlock);	
	for (i=0; i < NUM; i++){
		pthread_join(tid[i], NULL);
	}
	pthread_rwlock_destroy(&rwlock);
	
	printf("expect:%d\nactual:%d\n", NUM*LOOP, g);	
	return 0;
}

