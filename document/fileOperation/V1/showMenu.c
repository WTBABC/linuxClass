#include "myFile.h"
#include <termio.h>

int scanKeyboard_1(){		//获取按键的函数
	int in; 
	struct termios new_settings;
	struct termios stored_settings;
	tcgetattr(0, &stored_settings);
	new_settings = stored_settings;
	new_settings.c_lflag &= (~ICANON);
	new_settings.c_cc[VTIME] = 0;
	tcgetattr(0, &stored_settings);
	new_settings.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &new_settings);
	
	in = getchar();

	tcsetattr(0, TCSANOW, &stored_settings);
	return in;	
}
void showMenu_1(int flag){	//flag，菜单的第flag项为当前选择项
	int i;	
	char menu[6][30] = {"退出","创建新文件", "写文件", "读文件", "查看当前文件的权限", "修改文件权限"};
	system("clear");
	printf("******************************\n");
	for (i=0; i < 6; i++){
		if (i == flag)
			printf("\033[0;37;44m%d:%s\033[0m\n", i, menu[i]);
		else 
			printf("%d:%s\n", i, menu[i]);
	}
	printf("******************************\n");
}
