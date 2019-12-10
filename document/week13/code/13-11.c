#include "my.h"

volatile int global = 0;
void alarm_handler(int signo){
	global = 1;
	puts("catch alarm!\n");
}

int main(){
	clock_t start, end;
	struct tms buffer;
	
	signal(SIGALRM, alarm_handler);
	start = times(&buffer);
	alarm(1);
	while (!global);
	end = times(&buffer);
	printf("%ld clock ticks per second (start=%ld, end=%ld)\n", end-start, start, end);
	printf("sysconf(_SC_CLK_TCK) = %ld\n", sysconf(_SC_CLK_TCK));
	
	return 0;
}
