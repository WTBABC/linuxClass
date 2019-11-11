#include "my.h"

int main(){
	int ways = 1;
	printf("caller:pid = %d, ppid = %d\n", getpid(), getppid());
	if (ways == 0)	
		execl("test1.out", "./test1.out", "ABC", "123", "456", NULL);
	else if (ways == 1){
		char* arg[] = {"./test1.out", "ABC", "123", "456", NULL};	
		execv("test1.out", arg);	
	}
	printf("after calling\n");
	return 0;
}
