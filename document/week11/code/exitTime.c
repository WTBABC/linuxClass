#include "my.h"
#include <sys/time.h>

int main(){
	struct timeval tv1, tv2;
	struct timezone tz;
	int pid, s;	
	if ((pid = fork()) == 0){		
		gettimeofday(&tv2, &tz);
		printf("pid=%d, exit time %lu\n", getpid(), tv2.tv_usec);
		exit(0);		
	}
	if ((pid = fork()) == 0){
		gettimeofday(&tv2, &tz);
		printf("pid=%d, exit time %lu\n", getpid(), tv2.tv_usec);
		exit(1);
	}
	gettimeofday(&tv1, &tz);
	printf("parent begin %lu\n", tv1.tv_usec);
	while ((pid=wait(&s)) > 0){
		printf("%d %d\n", WEXITSTATUS(s), pid);
	}
	return 0;
}
