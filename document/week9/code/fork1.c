#include "my.h"

int g = 99;
int main(){
	int i, pid;
	static int f=19;
	pid = fork();
	if (pid < 0){
		perror("fork failed!\n");
		exit(1);	
	} else if (pid == 0) {
		printf("child: pid = %d, ppid = %d\n", getpid(), getppid());
		i = 100;
		g = 101;
		f = 238;
		printf("i = %d, g = %d, f = %d\npi = %p, pg = %p, pf = %p\n", i, g, f, &i, &g, &f);
		exit(123);	
	}
	
	sleep(5);
	printf("parent: pid = %d, ppid = %d\n", getpid(), getppid());
	printf("parent: i = %d, g = %d, f = %d\npi = %p, pg = %p, pf = %p\n", i, g, f, &i, &g, &f);
	exit(0);
} 
