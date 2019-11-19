#include "my.h"

int main(){
	int pid, s;
	if ((pid=fork()) < 0){
		perror("failed to fork\n");
		return -1;
	}
	else if (pid == 0){
		printf("%d:child is running now!\n", getpid());
		while(1);
		printf("%d:child is exit\n", getpid());
		exit(120);
	}
	else{
		while((pid=wait(&s)) != -1){
			if (WIFEXITED(s)){
				printf("child %d is exit, exit code = %d\n", pid, WEXITSTATUS(s));
			}		
			else if (WIFSIGNALED(s)){
				printf("child %d exit by signal. signal NO = %d\n", pid, WTERMSIG(s));
			}
			else{
				printf("Not know!\n");
			}
		}
		printf("%d:parent is exit\n", getpid());
	}
	return 0;
}
