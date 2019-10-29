#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
char buf[] = {"write to stdout"};
int main(){
	pid_t id;
	write(STDOUT_FILENO,buf, sizeof(buf)-1);
	printf("testdata\n");	//\n
	if ((id=fork()) < 0){
		perror("error");
		exit(0);
	}
	return 0;
}
