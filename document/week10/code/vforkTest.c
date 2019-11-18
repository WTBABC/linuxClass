#include "my.h"

int a = 5;
int main(){
	int var=1;
	pid_t pid = vfork();
	if (pid < 0){
		printf("process error!\n");
		_exit(1);
	} else if (pid == 0){
		var ++;
		a ++;
		exit(0);
	} 
	printf("parents: id = %d, var = %d a = %d", getpid(), var, a);
	exit(0);
}
