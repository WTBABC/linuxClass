#include "/home/rlk/Documents/myGit/document/week5/dynamiclib/test1/my.h"//test1/my.h
#include <stdlib.h>
#include <dlfcn.h>
int main(){
	int a[MAXSIZE];
	void* handle;
	void (*f1)();
	int (*f2)();
	int (*f3)();
	int (*f4)();
	char* error;
	srand(time(NULL));
	handle = dlopen("test1/libtest1.so", RTLD_LAZY);
	if ((error=dlerror()) != NULL){
		perror("load failed!\n");
		exit(1);
	}
	f1 = dlsym(handle, "randinit");
	if ((error=dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	f2 = dlsym(handle, "show");
	if ((error=dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	f3 = dlsym(handle, "max");
	if ((error=dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	f4 = dlsym(handle, "sum");
	if ((error=dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	f1(a, MAXSIZE);		//randinit
	printf("main1.c\n");
	f2(a, MAXSIZE);
	printf("max number = %d\n", f3(a, MAXSIZE));
	printf("sum = %d\n", f4(a,MAXSIZE));
	
	dlclose(handle);
	if ((error=dlerror()) != NULL){
		fprintf(stderr, "%s\n", error);
		exit(1);
	}
	return 0;
}
