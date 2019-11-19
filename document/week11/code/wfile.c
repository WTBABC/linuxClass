#include "my.h"
#include <string.h>
int main(){
	pid_t pid1, pid2;
	FILE* fp;
	char buf[31], num[] = "0123456789";
	int i=0, tmp;	
 	fp = fopen("user.dat", "a+");
	if (fp == NULL){
		perror("open failed!\n");
		exit(0);
	}
	if ((pid1 = fork()) == 0){
		/*pid_t pid = getpid();
		printf("child1:%d\n", pid);
		fwrite(&pid, sizeof(int), 1, fp);*/
		fprintf(fp, "child1=%d,", getpid());
		for (i=0; i < 10; i++){
			fwrite(num+i, sizeof(char), 1, fp);
		}
		exit(0);		
	}
	if ((pid2 = fork()) == 0){
		/*pid_t pid = getpid();
		printf("child2:%d\n", pid);
		fwrite(&pid, sizeof(int), 1, fp);*/
		fprintf(fp, "\nchild2=%d,", getpid());
		for (i=0; i < 10; i++){
			fwrite(num+i, sizeof(char), 1, fp);
		}
		exit(0);
	}
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	tmp = fread(buf, sizeof(buf), 1, fp);	
	printf("parent : %d, 读取的长度为%d, 字符串<%s>长度为%lu\n", getpid(), tmp, buf, strlen(buf));
	system("cat user.dat");
	printf("\n");
	system("rm user.dat");
	fclose(fp);
	return 0;
}
