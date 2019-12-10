#include "my.h"

#define BUF_4K 4*1024
#define BUF_8K 8*1024
#define BUF_12K 12*1024

int main(){
	char a[BUF_4K];
	char b[BUF_8K];
	char c[BUF_12K], buf[1024*4] = {0};
	int fd[2], ret, fd1, n;
	pid_t pid;
	
	memset(a, 'A', sizeof(a));
	memset(b, 'B', sizeof(b));
	memset(c, 'C', sizeof(c));
	
	
	ret = pipe(fd);
	if (ret == -1) {
		fprintf(stderr, "create pipe error (%s)\n", strerror(errno));
		exit(-1);
	}
	
	pid = fork();
	if (pid == -1){
		fprintf(stderr, "first fork error (%s)\n", strerror(errno));
		exit(-2);
	}
	else if (pid == 0){
		int loop = 0;
		close(fd[0]);
		while (loop++ < 10){
			ret = write(fd[1], a, sizeof(a));
			printf("[child 1] pid=%d write %d bytes to pipe\n", getpid(), ret);	
		}
		exit(0);
	}
	pid = fork();
	if (pid == -1){
		fprintf(stderr, "second fork error (%s)\n", strerror(errno));
		exit(-3);
	}
	else if (pid == 0){
		int loop = 0;
		close(fd[0]);
		while (loop++ < 10){
			ret = write(fd[1], b, sizeof(b));
			printf("[child 2] pid=%d write %d bytes to pipe\n", getpid(), ret);	
		}
		exit(0);
	}
	pid = fork();
	if (pid == -1){
		fprintf(stderr, "third fork error (%s)\n", strerror(errno));
		exit(-4);
	}
	else if (pid == 0){
		int loop = 0;
		close(fd[0]);
		while (loop++ < 10){
			ret = write(fd[1], c, sizeof(c));
			printf("[child 3] pid=%d write %d bytes to pipe\n", getpid(), ret);	
		}
		exit(0);
	}

	close(fd[1]);
	sleep(2);
	fd1 = open("./test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);	
	n=1;
	
	while ((ret = read(fd[0], buf, sizeof(buf))) != 0){
		printf("n = %02d, pid=%d read %d bytes from pipe, buf[4095]=%c\n", n++, getpid(), ret, buf[4095]);
		write(fd1, buf, ret);
	}
	close(fd1);
	return 0;
}

