#include <stdio.h>
#include <unistd.h>
#include <time.h>

void init_daemon();

int main(){
	FILE* fp;
	time_t t;
	init_daemon();
	while (1){
		sleep(10);
		if ((fp = fopen("6-8.log", "a")) >= 0){
			t = time(0);
			fprintf(fp, "运行中，时间： %s\n", asctime(localtime(&t)));
			fclose(fp);
		}		
	}
	return 0;
}
