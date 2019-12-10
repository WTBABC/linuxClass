#include "my.h"
#define NUM 4

typedef struct {
	int n, s;
}IN;

void * fun(void * arg){
	IN* in = (IN*) arg;
	int i=0, sum=0;

	printf("worker%d : s=%d\n", in->n, in->s);
	for (i=1; i <= in->s; i++)
		sum += i;
	printf("worker%d : pthread_self=%lx, sum of %d = %d\n", in->n, pthread_self(), in->s, sum);
	pthread_exit(NULL);
	return NULL;	
}
int main(){
	pthread_t tid[NUM];
	int i,ret[NUM];
	IN d;

	for (i=0; i < NUM; i++){
		d.n = i;
		d.s = (i+1)*100;
		ret[i] = pthread_create(tid+i, NULL, fun, (void*) &d);
		if (ret[i] != 0){
			perror("create failed\n");
			return -1;
		}
	}
	pthread_exit(NULL);
	printf("Boss %d : done!\n", getpid());
}
	//pthread_join(tid[i], NULL);

	/*for (i=0; i < NUM; i++)
		//
		pthread_detach(tid[i]);*/
