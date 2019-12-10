#include "my.h"

volatile int global = 0;
void alarm_handler(int signo){
	if (global == 10) return;
	global ++;
	printf("%d catch alarm!\n", global);
}

int main(){
	pid_t pid;
	clock_t start, end;
	struct tms buffer;
	
	signal(SIGALRM, alarm_handler);
	pid = fork();
	start = times(&buffer);
	if (pid < 0){
		perror("fork failed!\n");
		return -1;
	}
	else if (pid == 0) {
		int i=0;
		for ( ; i < 10; i++)
			alarm(1);
		exit(0);		
	}
	else {
		while (global != 10);
		kill(pid, 9);
		end = times(&buffer);
		printf("%ld clock ticks per second (start=%ld, end=%ld)\n", end-start, start, end);
		printf("sysconf(_SC_CLK_TCK) = %ld\n", sysconf(_SC_CLK_TCK));
		wait(NULL);
	}
	return 0;
}
