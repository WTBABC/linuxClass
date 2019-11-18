#include "my.h"
static void fun1(){
	printf("invoked callbackfun!\n");
}
int main(){
	FILE *fp;
	char buf[] = "HELLO   ";
	atexit(fun1);
	printf("%s", buf);
	if ((fp = fopen("test.txt", "w")) == NULL){
		perror("failed to open");
		return -1;
	}
	if (fputs(buf,fp) == EOF){
		perror("fail to fputs");
		return -1;
	}
	_exit(0);
}
