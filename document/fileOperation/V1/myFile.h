#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>

#define KEY_UP	65						//上方向键
#define KEY_DOWN 66						//下方向键
#define KEY_LEFT 68						//左方向键
#define KEY_RIGHT 67					//右方向键
#define KEY_ENTER 10					//Enter键

#define CREATENFILE 1					//创建新文件
#define WRITEFILE 	2					//写文件
#define READFILE	3					//读文件
#define CHECKCHMOD 	4					//查看文件权限
#define ALTERCHMOD	5					//修改文件权限

#define MAXL 512						//写文件时缓冲区大小

void menu_1();							//主循环
int scanKeyboard_1();					//按键获取
void showMenu_1(int);					//显示菜单并高亮显示选择项
void funs_1(int);						//功能选择

void hideCursor_1();					//隐藏光标
void showCursor_1();					//显示光标

int createFile_1(char*);				//创建新文件，返回值为1时创建成功，0时创建失败
int writeFile_1(char*);					//写文件
int readFile_1(char*);					//读文件	
int viewFilePermissions_1(char*); 		//查看文件权限
int strJudge_1(char*);					//判断某种身份的访问权限
int alterFilePremission_1(char*);		//修改文件权限

