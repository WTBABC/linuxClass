#include "my.h"
int main(){
	int a[MAXSIZE];
	srand(time(NULL));
	randinit(a, MAXSIZE);
	show(a, MAXSIZE);
	printf("max number = %d\n", max(a, MAXSIZE));
	printf("sum = %d\n", sum(a,MAXSIZE));
	return 0;
}
