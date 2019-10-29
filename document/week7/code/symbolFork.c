#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int globa=0;
int main(){
	pid_t pid;
	int vari=1;
	printf("before fork\n");
	if ((pid = fork()) < 0){
		printf("fork error\n");
		exit(0);
	} else if (pid == 0){
		globa++;
		vari--;
		printf("Child changed\n");
		printf("child : globa = %d vari = %d\n", globa, vari);
	} else {
		sleep(1);
		printf("Parent did not changed\n");
		printf("parent : globa = %d vari = %d\n", globa, vari);
		exit(0);
	}
	return 0;
}
