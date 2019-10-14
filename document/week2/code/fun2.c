#include "uhead.h"

int urand(){
	return rand()%TMAXL;
}
int usum(int* a, int n){
	int sum=0, i;
	for (i=0; i < n; i++)
		sum += a[i];	
	return sum;
}
void ushow(int* a, int n){
	int i;
	for (i=0; i < n && i < UMAXL; i++)
		printf("\na[%d]=%d", i, a[i]);
	printf("\n");
}
int compare(const void* a, const void* b){
	return *(int*)a - *(int*)b;
}
void howLongQsort(int* a, int n){
	struct timeval tv1, tv2;
	struct timezone tz;
	gettimeofday(&tv1, &tz);
	qsort(a, n, sizeof(int), compare);
	gettimeofday(&tv2, &tz);
	printf("tv2.-tv1: %ld\n", tv2.tv_usec - tv1.tv_usec);
	printf("a[%d] = %d\n", n-1, a[n-1]);
}
void howLongMao(int* a, int n){
	struct timeval tv1, tv2;
	struct timezone tz;
	int i, j, uend, temp;
	gettimeofday(&tv1, &tz);
	for (i=0; i < n; i++){
		uend = n-i-1; 
		for (j=0; j < uend; j++){
			if (a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;		
			}
	
		}
	}
	gettimeofday(&tv2, &tz);
	printf("tv2.-tv1: %lu\n", tv2.tv_usec - tv1.tv_usec);
	printf("a[%d] = %d\n", n-1, a[n-1]);
}
void Mysort(int* a, int n){
	int i, j, temp, uend;
	for (i=0; i < n; i++){
		uend = n-i-1;
		for (j=0; j < uend; j++){
			if (a[j] > a[j+1]){
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}

void Syssort(int* a, int n){
	qsort(a, n, sizeof(int), compare);
}
