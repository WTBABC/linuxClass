#include "my.h"
int max(int *a, int n){
	int i, max = 0;	
	for (i=0; i < n; i++){
		if (a[i] > max)	max = a[i];	
	}
	return max;
}
int sum(int *a, int n){
	int all=0, i;
	for (i=0; i < n; i++)
		all += a[i];
	return all;
}
void show(int *a, int n){
	int i;	
	for (i=0; i < n; i++)
		printf("%4d : %d\n", i, a[i]);
}
