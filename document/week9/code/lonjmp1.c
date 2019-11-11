#include "my.h"
#include <setjmp.h>

static jmp_buf g_stack_env;
static void fun1();
static void fun2();

int main(){
	if (0 == setjmp(g_stack_env)){
		printf("Normal flow\n");
		fun1();
	} else {
		printf("Long jump flow\n");
	}
	return 0;
}
static void fun1(){
	printf("fun1\n");
	fun2();
}
static void fun2(){
	printf("fun2\n");
	longjmp(g_stack_env, 1);
	printf("leave fun2\n");
}
