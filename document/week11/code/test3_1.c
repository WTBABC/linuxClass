#include "my.h"
void pr_exit(int s, pid_t pid){
	int sig;
	if (WIFEXITED(s)){
		printf("process %d normal termination, exit status = %d\n", pid, WEXITSTATUS(s));
	}
	else if (WIFSIGNALED(s)){
		sig = WTERMSIG(s);
		printf("process %d abnormal termination, signal number = %d%s\n", pid, sig,
		#ifdef WCOREDUMP
				WCOREDUMP(s) ? "core file generated":"");
		#else
				"");
		#endif
			psignal(sig, "");
	}
	else if (WIFSTOPPED(s)){
		sig = WSTOPSIG(s);
		printf("process %d stopped, siginal number = %d\n", pid, sig);
		psignal(sig, "");
	}
}

int main(){
	int pid, s;
	if ((pid = fork()) == 0){
		exit(0);
	}
	if ((pid = fork()) == 0){
		abort();
	}
	if ((pid = fork()) == 0){
		int zero = 0;
		s = s/zero;
		exit(0);
	}
	while((pid=wait(&s)) > 0){
		pr_exit(s, pid);
	}
	printf("wait over!\n");
	return 0;
}
