#include "my.h"
#define NUM 4

typedef struct{
	int No,
		begin;
}IN;
typedef struct{
	int sum;
	struct timeval start,
				   over;
}OUT;

void * fun(void *arg){
	IN *pt = (IN*)arg;
	int i = pt->begin, end = pt->begin + 99;
	OUT* out = (OUT*) malloc(sizeof(OUT));	

	gettimeofday(&out->start, NULL);		
	out->sum = 0;	
	printf("%d thread : tid=%lx\n", pt->No, pthread_self());
	for ( ; i <= end; i++)
		out->sum += i;
	gettimeofday(&out->over, NULL);

	pthread_exit(out);
}
int main() {
	pthread_t tid[NUM];
	int i, ret[NUM];
	IN in[NUM];
	OUT* out[NUM];
	
	for (i=0; i < NUM; i++){
		in[i].No = i;
		in[i].begin = i*100 + 1;

		ret[i] = pthread_create(tid+i, NULL, fun, in+i);
		if (ret[i] != 0){
			printf("thread create failed!\n");
			return -1;
		}
	}
	for (i=0; i < NUM; i++)
	{
		pthread_join(tid[i], (void**)(out+i));
	}
	for (i=0; i < NUM; i++){
		printf("%d : %3d~%d = %5d, start = %ld:%ld, over = %ld:%ld\n", 
				in[i].No, in[i].begin, in[i].begin+99, out[i]->sum,
				out[i]->start.tv_sec, out[i]->start.tv_usec, out[i]->over.tv_sec, out[i]->over.tv_usec);
				//out[i].start.tv_sec, out[i].start.tv_usec, out[i].over.tv_sec, out[i].over.tv_usec);
	}
	for (i=0; i < NUM; i++)
		free(out[i]);
	return 0;
}
