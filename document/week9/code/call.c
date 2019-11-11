#include "my.h"

int main(){
	char* arg[] = {"./hello.out", "123", NULL};
	printf("pid = %d\n", getpid());	
	execvp("hello.out", arg);
	printf("after!\n");
	return 0;
}
