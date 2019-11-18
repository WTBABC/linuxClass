#include "my.h"

char a[10] = {0};
int g = 9999;

int main(){
	int s = 8888, i;
	static int k = 6666;
	printf("var address in pro1:\n");
	printf("&a=%16p\t&g=%16p\t&k=%16p\t&s=%16p\n", a, &g, &k, &s);
	for (i=0; i < 10; i++){
		printf("pro1%d: run %d time!\n", getpid(), i);
	}
	return 0;
}
