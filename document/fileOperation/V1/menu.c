#include "myFile.h"
void menu_1(){
	int key1, key2, key3, cnt = 0;			//cnt记录当前选择项
	hideCursor_1();							//隐藏光标
	showMenu_1(cnt);						//选择项高亮显示
	while(1){
		key1 = scanKeyboard_1();			//获取键盘响应	
		if (key1 == 27){	
			key2 = scanKeyboard_1();	
			if (key2 == 91) {						
				key3 = scanKeyboard_1();	//方向键有三个字符， 前两个字符为27 91
				if (key3 == KEY_UP){	
					cnt = (--cnt+6)%6;
				} else if (key3 == KEY_DOWN){
					cnt = ++cnt%6;
				} else if (key3 == KEY_LEFT){
					cnt = (--cnt+6)%6;
				} else if (key3 == KEY_RIGHT){
					cnt = ++cnt%6;		
				} else {
					continue;
				}
				showMenu_1(cnt);			//高亮显示的位置需改变时，重新打印菜单
			}
		} else if (key1 == KEY_ENTER){		//回车键只有一个字符
			if (cnt == 0)	{
				showCursor_1();				//显示光标 
				break;
			}		
			funs_1(cnt);
		} else {
			system("clear");				//按下其他键会显示，所以需要清屏
			showMenu_1(cnt);				//重新打印菜单
		}
	}
}
void hideCursor_1(){
	printf("\033[?25l");
}
void showCursor_1(){
	printf("\033[?25h");
}
