#include "my.h"
#include <stdlib.h>
#include <string.h>

static void	mem_leak1(){//指针未释放
	char* p = malloc(1);		
}
static void	mem_leak2(){//文件设备未释放
	FILE* fp = fopen("text.txt", "w");	
}
static void	mem_overrun1(){//一个字节的空间放入两个字节的数据
	char* p = malloc(1);
	*(short*) p = 2;
	free(p);
}
static void	mem_overrun2(){//5个字符的空间放入6个字符
	char array[5];
	strcpy(array, "01234");
}
static void	mem_double_free(){//释放两次指针
	char* p=malloc(1);
	free(p);
	free(p);
}
static void mem_free_wild_pointer(){//释放野指针
	char* p;
	free(p);
}
int main(){
	mem_leak1();
	mem_leak2();
	mem_overrun1();
	mem_overrun2();
	mem_double_free();
	mem_free_wild_pointer();
	return 0;
}
