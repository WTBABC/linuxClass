#include "my.h"

static void callback1(){
	printf("1: Running after main!\n");
}
static void callback2(){
	printf("2: Running after main!\n");
}

int main(){
	atexit(callback1);
	atexit(callback2);
	printf("callback1: pid = %d, ppid = %d\n", getpid(), getppid());
	while (1)
		sleep(1);
	return 0;
}
