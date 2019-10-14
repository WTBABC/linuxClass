#include "my.h"
int main(){
	int a[MAXSIZE];
	//int i=0;
	srand(time(NULL));
	randinit(a, MAXSIZE);
	/*for ( ; i < MAXSIZE; i++)
		printf("%d ", a[i]);
	printf("\n");*/
	printf("max number = %d\n", max(a, MAXSIZE));
	return 0;
}
