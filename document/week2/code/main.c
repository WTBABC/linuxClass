#include "uhead.h"
int a[TMAXL];
int main(){
	int i;
	struct timeval tv1, tv2;
	struct timezone tz;
	srand(time(0));
	for (i=0; i < TMAXL; i++)
		a[i] = urand();	
	//howLongQsort(a, TMAXL);
	gettimeofday(&tv1, &tz);
	Syssort(a, TMAXL);
	gettimeofday(&tv2, &tz);
	printf("Syssort spend time: %ld\n", tv2.tv_usec-tv1.tv_usec);

	for (i=0; i < TMAXL; i++){
		a[i] = urand();
	//	printf("%d ", a[i]);
	}
	printf("\n");
	//howLongMao(a, TMAXL);
	gettimeofday(&tv1, &tz);
	Mysort(a, TMAXL);
	gettimeofday(&tv2, &tz);
//	for (i=0; i < TMAXL; i++)
//		printf("%d ", a[i]);
	printf("Mysort spend time: %ld\n", tv2.tv_usec-tv1.tv_usec);

	return 0;
}
