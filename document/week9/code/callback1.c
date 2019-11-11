#include "my.h"

static void callback1(){
	printf("1: Running after main!\n");
}
static void callback2(){
	printf("2: Running after main!\n");
}
static void __attribute__ ((destructor)) after_main(){
	printf("after callback\n");
}
int main(){
	atexit(callback1);
	atexit(callback2);
	printf("callback1: pid = %d, ppid = %d\n", getpid(), getppid());
	return 0;
}
