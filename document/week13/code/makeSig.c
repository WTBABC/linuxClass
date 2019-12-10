#include "my.h"

void sigroutine(int dunno){
	switch(dunno){
		case 1:
				printf("Get a signal SIGHUP\n");
				break;
		case 2:
				printf("Get a signal SIGINT\n");
				break;
		case 3:
				printf("Get a signal SIGQUIT\n");
				break;	
	}
}
int main(){
	printf("process id = %d\n", getpid());
	signal(SIGHUP, sigroutine);
	signal(SIGINT, sigroutine);
	signal(SIGQUIT, sigroutine);
	while (1);
	return 0;
}
