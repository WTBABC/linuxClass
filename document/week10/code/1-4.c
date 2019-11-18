#include "my.h"

static void __attribute__((constructor)) before_main(){
	printf("\n-----constructor-----\n");
}
static void __attribute__((destructor)) after_main(){
	printf("\n-----destructor-----\n");
}
void callback1(){
	printf("\ncallback1\n");
}
void callback2(){
	printf("\ncallback2\n");
}
int main(){
	atexit(callback1);
	atexit(callback2);
	FILE* fp;
	char buf[] = "test data from full buffer!\n";
	if ((fp = fopen("test.dat", "w+")) == NULL){
		printf("failed to fopen!\n");
		return -1;
	}
	if (fputs(buf,fp) == EOF){
		printf("failed to fputs!\n");
		return -1;
	}
	printf("printf:data from line buffer");
	//exit(0);
	//_exit(0);
	return 0;
}
