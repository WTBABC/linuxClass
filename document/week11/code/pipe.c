#include "my.h"
#include <string.h>
int main(){
	pid_t result;
	int r_num;
	int pipe_fd[2];
	char buf_r[100];
	memset(buf_r, 0, sizeof(buf_r));
	if (pipe(pipe_fd) < 0){
		printf("create pipe failed!\n");
		exit(1);
	}
	result = fork();
	if (result < 0){
		perror("fork failed!\n");
		exit(2);
	} else if (result == 0){
		sleep(1);
		close(pipe_fd[1]);
		if ((r_num = read(pipe_fd[0], buf_r, 100)) > 0){
			printf("子进程从管道读取%d个字符，读取的内容为\"%s\"\n", r_num, buf_r);
		}
		close(pipe_fd[0]);
		exit(0);
	} else {
		char str1[] = "第一串文字",
			 str2[] = "第二串文字";
		close(pipe_fd[0]);
		if (write(pipe_fd[1], str1, strlen(str1)) != -1){
			printf("父进程向管道写入\"%s\"!\n", str1);
		}
		if (write(pipe_fd[1], str2, strlen(str1)) != -1){
			printf("父进程向管道写入\"%s\"!\n", str2);
		}
		close(pipe_fd[1]);
		waitpid(result, NULL, 0);
		exit(0);
	}
	return 0;
}
