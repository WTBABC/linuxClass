#include "my.h"

int g = 10;
int main(){
	int s = 20;
	static int k = 30;
	int status;
	pid_t pid = fork();
	if (pid < 0){
		printf("fork failed!\n");
		return -1;
	}
  	else if (pid == 0){
		printf("child pid=%d : \n", getpid());
		printf("&g=%16p\t&k=%16p\t&s=%16p\n", &g, &k, &s);
		g = 100;
		s = 200;
		k = 300;
		execl("./pro1", "pro1", NULL);
		printf("child after g=%d s=%d k=%d", g, s, k);	
		exit(12);	
	}
	else{
		wait(&status);
		printf("child exit code = %d\n", WEXITSTATUS(status));
		printf("parent pid=%d : ", getpid());
		printf("&g=%16p\t&k=%16p\t&s=%16p\n", &g, &k, &s);
		printf("parent after g=%d s=%d k=%d\n", g, s, k);	
		return 0;
	}
}
