#include "my.h"
int x = 100;
int main(int argc, char* argv[]){
	int i;
	int y=0;
	static int w = 33;
	printf("test1:pid = %d, ppid = %d\n", getpid(), getppid());
	printf("test1:address x=%p, y=%p, w=%p\n", &x, &y, &w);
	for (i=0; i < argc; i++){
		printf("%s\n", argv[i]);
	}
	return 0;
}
