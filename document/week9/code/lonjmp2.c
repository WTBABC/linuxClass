#include "my.h"
#include <setjmp.h>

static jmp_buf g_stack_env;
static void fun1(int*, int*, int*);

int main(){
	int a = 1;
	int b = 2;
	int c = 3;
	if (0 == setjmp(g_stack_env)){
		printf("Normal flow\n");
		printf("main 1:  a=%d, b=%d, c=%d\n", a, b, c);
		fun1(&a, &b, &c);
	} else {
		printf("after fun1\n");
		printf("main 2:  a=%d, b=%d, c=%d\n", a, b, c);
	}
	return 0;
}
static void fun1(int* a, int* b, int* c){
	printf("fun1\n");
	*a = 2;
	*b = 3;
	*c = 4;
	printf("fun1:  a=%d, b=%d, c=%d\n", *a, *b, *c);
	longjmp(g_stack_env, 1);
	printf("leave jump\n");
}

//-Wall -O2	//O2优化
