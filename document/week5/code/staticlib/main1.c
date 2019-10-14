#include "/home/rlk/Documents/myGit/document/week5/code/test1/my.h"//
int main(){
	int a[MAXSIZE];
	srand(time(NULL));
	randinit(a, MAXSIZE);
	printf("main1.c\n");
	printf("max number = %d\n", max(a, MAXSIZE));
	return 0;
}
