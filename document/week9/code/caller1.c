#include "my.h"
int main(){
	int ret;
	printf("caller1:pid=%d, ppid=%d\n", getpid(), getppid());
	ret = system("./test1.out");
	printf("after calling!\n");
	sleep(2);
	return 0;
}
