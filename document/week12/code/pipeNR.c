#include "my.h"

void sighandler(int signo);
int main(){
	int fd[2];
	pid_t pid;
	
	if (signal(SIGPIPE, sighandler) == SIG_ERR){
		fprintf(stderr, "signal error (%s)\n", strerror(errno));
		return -1;
	}
	if (pipe(fd) == -1){
		fprintf(stderr, "create error (%s)\n", strerror(errno));
		return -2;
	}
	pid = fork();
	if (pid < 0){
		fprintf(stderr, "fork error (%s)\n", strerror(errno));
		return -3;
	}	
	else if (pid == 0){
		fprintf(stdout, "[child] i will close the last read of pipe, pid=%d, ppid=%d\n", getpid(), getppid());
		//sleep(300);
		close(fd[0]);
		exit(0);		
	}
	else {
		int ret;
		sleep(1);
		close(fd[0]);
		
		ret = write(fd[1], "hello", 5);
		printf("call sighandler\n");
		if (ret == -1){
			fprintf(stderr, "parent write error (%s)\n", strerror(errno));
		}
	}
	return 0;
}
void sighandler(int signo){
	printf("[parent] catch a SICPIPE signal and signum=%d\n", signo);
}
