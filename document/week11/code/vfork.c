#include "my.h"

int main(){
	pid_t pid;
	FILE* fp = fopen("./in.txt", "a+");	
	char buf[] = "ABC\n";
	if (fp == NULL){
		perror("open in.txt failed!\n");
		exit(1);
	}
	
	if ((pid = vfork()) < 0){
		perror("fork failed!\n");
	} else if (pid == 0){
		printf("child=%d, begin write!\n", getpid());
		fwrite(buf, sizeof(buf), 1, fp);	
		printf("child finish write and exit!\n");	
		exit(0);
	} else {
		printf("parent begin write!\n");
		fwrite(buf, sizeof(buf), 1, fp);	
		printf("parent finish write and exit!\n");
	}
	system("cat in.txt");
	system("rm in.txt");
	return 0;
}
