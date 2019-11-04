#include "myFile.h"

void funs_1(int index){
	char fileName[256];
	
	showCursor_1();						//显示光标，提示输入
	printf("请输入文件名 >> ");			//获取文件名
	scanf(" %s", fileName);
	getchar();	//吞掉回车，不然会被按键响应函数获取
	switch(index){
		case CREATENFILE:
			createFile_1(fileName);
			break;
		case WRITEFILE:
			writeFile_1(fileName);
			break;
		case READFILE:
			readFile_1(fileName);
			break;
		case CHECKCHMOD:
			viewFilePermissions_1(fileName);
			break;
		case ALTERCHMOD:
			alterFilePremission_1(fileName);
			break;
		default:
			break;
	}	
	printf("Enter键继续，方向键返回菜单\n");
	hideCursor_1();					//隐藏光标
}
// sys/types sys/stat chmod修改文件权限

//创建新文件
int createFile_1(char* fileName){
	FILE* fp = NULL;
	int end=0;
	
	fp = fopen(fileName, "wt+x");
	printf("%s文件创建", fileName);
	if (fp == NULL){
		end = 0;
		printf("失败！文件已存在或文件名不符合规则\n");
		return -1;
	} 
	
	end = 1;
	printf("成功！\n");	
	fclose(fp);
	fp = NULL;
	return end;
}

//写文件
int writeFile_1(char* fileName){
	FILE* fp = NULL;
	char buf[MAXL];
	int len, res;
	
	fp = fopen(fileName, "a+");
	if (fp == NULL){
		printf("文件打开失败");
		return 1;
	}
	//成功打开文件	
	printf("输入内容 >> ");
	gets(buf);
	len = strlen(buf);
	res = fwrite(buf, sizeof(char), len, fp); 	
	if (res != len){
		printf("写入失败\n");	
	} else {
		printf("写入成功\n");	
	}
	fclose(fp);
	return 0;
}

int readFile_1(char* fileName){
	FILE* fp = NULL;
	char buf[MAXL];
	int len;
	
	fp = fopen(fileName, "r");
	if (fp == NULL){
		printf("打开%s文件失败！\n", fileName);
		return 1;
	}
	
	printf("\n文件内容如下 >> \n");
	while (fread(buf, sizeof(char), MAXL, fp)){
		printf("%s", buf);
	}
	printf("\n%s文件内容已显示完整。\n\n", fileName);
	fclose(fp);
}

int viewFilePermissions_1(char* fileName){
	struct stat buf;
	int i;

	if (fileName == NULL){
		printf("文件名不能为空！\n");
		return 1;	
	}
	if (lstat(fileName, &buf) == -1){
		printf("获取文件权限失败！\n");
		return 1;
	}
	printf("%s文件的权限 >> ", fileName);
	
	for (i=8; i >= 0; i--){
		if (buf.st_mode & (1<<i)){
			switch(i%3){
				case 2:
						printf("r");
						break;
				case 1:
						printf("w");
						break;
				case 0:
						printf("x");
						break;
				default:
						break;
			}
		} else {
			printf("-");
		}
	} 
	printf("\n");
}
int strJudge_1(char* str){
	if (!strcmp(str, "---")){
		printf("\n%s\n", str);
		return 0;
	} else if (!strcmp(str, "r--")){
		return 1;
	} else if (!strcmp(str, "-w-")){
		return 2;
	} else if (!strcmp(str, "--x")){
		return 3;
	} else if (!strcmp(str, "rw-")){
		return 4;
	} else if (!strcmp(str, "r-x")){
		return 5;
	} else if (!strcmp(str, "-wx")){
		return 6;
	} else if (!strcmp(str, "rwx")){
		return 7;
	} else {
		return -1;
	}
}
int alterFilePremission_1(char* fileName){
	char str[15], cp[4];
	mode_t mode = 0;	
	int i;	
	
	if (fileName == NULL){
		printf("文件名读取失败！\n");
		return 1;
	}

	printf("请输入更改后的权限(格式如：rw-rw-rw-) >> ");
	gets(str);
	for (i=0;  i < 3; i++){
		strncpy(cp, str+i*3, 3);				//取得其中的某一组权限
		switch(strJudge_1(cp)){
			case 0:
					if(i == 0)	mode = mode | !S_IRWXU;
					else if (i == 1) 	mode = mode | !S_IRWXG;
					else if (i == 2)	mode = mode | !S_IRWXO;
					break;
			case 1:
					if(i == 0)	mode = mode | S_IRUSR;
					else if (i == 1) 	mode = mode | S_IRGRP;
					else if (i == 2)	mode = mode | S_IROTH;
					break;
			case 2:
					if(i == 0)	mode = mode | S_IWUSR;
					else if (i == 1) 	mode = mode | S_IWGRP;
					else if (i == 2)	mode = mode | S_IWOTH;
					break;
			case 3:
					if(i == 0)	mode = mode | S_IXUSR;
					else if (i == 1) 	mode = mode | S_IXGRP;
					else if (i == 2)	mode = mode | S_IXOTH;
					break;
			case 4:
					if(i == 0)	mode = mode | S_IRUSR | S_IWUSR;
					else if (i == 1) 	mode = mode | S_IRGRP | S_IWGRP;
					else if (i == 2)	mode = mode | S_IROTH | S_IWOTH;
					break;
			case 5:
					if(i == 0)	mode = mode | S_IRUSR | S_IXUSR ;
					else if (i == 1) 	mode = mode | S_IRGRP | S_IXGRP;
					else if (i == 2)	mode = mode | S_IROTH | S_IXOTH;
					break;
			case 6:
					if(i == 0)	mode = mode | S_IWUSR | S_IXUSR;
					else if (i == 1) 	mode = mode | S_IWGRP | S_IXGRP;
					else if (i == 2)	mode = mode | S_IWOTH | S_IXOTH;
					break;
			case 7:
					if(i == 0)	mode = mode | S_IRWXU;
					else if (i == 1) 	mode = mode | S_IRWXG;
					else if (i == 2)	mode = mode | S_IRWXO;
					break;
			default:
					printf("输入有误！\n");
					return 2;
		}
	}

	if (chmod(fileName, mode) < 0){
		printf("文件权限修改失败！\n");
		return -1;
	} else {
		printf("文件权限修改成功\n");
	}
}
