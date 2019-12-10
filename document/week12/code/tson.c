#include "my.h"
#include <string.h>
#define NUM 10
int main() {
	pid_t pid1, pid2, pid3;
	int pipe1[2], pipe2[2];
	int i, sum=0;
	char buf[] = "0123456789";
	if (pipe(pipe1) < 0){
		perror("创建管道1失败\n");
		exit(1);
	}
	if ((pid1 = fork()) == 0){
		printf("1 begin\n");
		close(pipe1[0]);
		for (i=0; i < NUM; i++){
			write(pipe1[1], buf+i, 1);
		}
		close(pipe1[1]);
		printf("1 end\n");
		exit(10);
	} else if (pid1 < 0){
		perror("创建进程1失败\n");
		exit(3);
	}
		
	if (pipe(pipe2) < 0){
		perror("创建管道2失败\n");
		exit(2);
	}
	if ((pid2 = fork()) == 0){
		printf("2 begin\n");
		close(pipe1[1]);
		for (i=0; i < NUM; i++){
			read(pipe1[0], buf+i, 1);	
		}
		close(pipe1[0]);
			
		close(pipe2[0]);
		write(pipe2[1], buf, strlen(buf));
		printf("2 end\n");
		close(pipe2[1]);
		exit(20);
	} else if (pid2 < 0){
		perror("创建进程2失败\n");
		exit(4);
	}
	if ((pid3 = fork()) == 0){
		printf("3 begin\n");
		close(pipe2[1]);
		for (i=0; i < NUM; i++){
			read(pipe2[0], buf+i, 1);
			sum += buf[i]-'0';		
		}
		printf("read from pipe2 : %s\n", buf);
		printf("sum = %d\n", sum);
		exit(30);	
	} else if (pid3 < 0){
		perror("创建进程3失败\n");
		exit(5);
	}
	
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	waitpid(pid3, NULL, 0);
	printf("over\n");
	return 0;
}
