#include "my.h"
#include <string.h>
//测试管道的大小（64KB），一直往管道写入数据，当无法将数据写入即管道满了时，退出子进程
int main(){
	pid_t pid;
	int pipe_fd[2];
	unsigned blocksize[] = {1024*1024, 1024, 1};
	int i, count, maxn=0, tmp;
	if (pipe(pipe_fd) < 0){
		perror("创建管道失败!\n");
		exit(1);
	}
	if ((pid = fork()) < 0){
		perror("创建子进程失败!\n");
		exit(2);
	} else if (pid == 0){
		close(pipe_fd[0]);
		char buf[] = "1234";
		while (1){
			tmp = write(pipe_fd[1], buf, 4);
			maxn = maxn + tmp; 
			printf("tmp=%d, maxn = %d\n", tmp, maxn);
		}
		close(pipe_fd[1]);
		exit(0);	
	} else {
		wait(NULL);
		printf("管道的大小为%d\n", maxn);		
	}
	return 0;
}
