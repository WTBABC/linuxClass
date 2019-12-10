#include "my.h"
#define NUM 4

typedef struct{
	int No,
		begin,
		sum;
	struct timeval start,
				   over;
}INAOUT;
void * fun(void *arg){
	INAOUT *pt = (INAOUT*)arg;
	int i = pt->begin, end = pt->begin + 99;
	
	gettimeofday(&pt->start, NULL);		
	pt->sum = 0;	
	printf("%d thread : tid=%lx\n", pt->No, pthread_self());
	for ( ; i <= end; i++)
		pt->sum += i;
	gettimeofday(&pt->over, NULL);

	return NULL;
}
int main() {
	pthread_t tid[NUM];
	int i, ret[NUM];
	INAOUT inaout[NUM];
	
	for (i=0; i < NUM; i++){
		inaout[i].No = i;
		inaout[i].begin = i*100 + 1;

		ret[i] = pthread_create(tid+i, NULL, fun, inaout+i);
		if (ret[i] != 0){
			printf("thread create failed!\n");
			return -1;
		}
	}
	for (i=0; i < NUM; i++)
	{
		pthread_join(tid[i], NULL);
	}
	for (i=0; i < NUM; i++){
		printf("%d : %d~%d = %d, start = %ld:%ld, over = %ld:%ld\n", 
				inaout[i].No, inaout[i].begin, inaout[i].begin+99, inaout[i].sum,
				inaout[i].start.tv_sec, inaout[i].start.tv_usec, inaout[i].over.tv_sec, inaout[i].over.tv_usec);
	}
	return 0;
}
