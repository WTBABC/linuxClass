#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[], char* env[]){
	int i=0; 
	extern char** environ; 
	printf("----------------------------env[]----------------------------\n");
	for ( ; env[i]; i++){
		printf("%s\n", env[i]);	
	} 
	printf("----------------------------environ[]----------------------------\n");
	for (i=0; environ[i]; i++){
		printf("%s\n", environ[i]);
	}
	printf("----------------------------getenv----------------------------\n");
	printf("%s\n", getenv("PATH"));
	return 0;
}
