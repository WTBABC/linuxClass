动态库文件一般以.so结尾（shared object），生成动态库文件要加上-shared和-fpic（position independent code 位置无关代码）选项，库文件名要以lib开头
gcc -fpic -shared fun1.c fun2.c -o libtest1.so	//用fun1.c和fun2.c生成动态库文件libtest1.so

1、隐式调用
gcc -I . -o calling.o -c calling.c 		//-I后接动态库文件所在目录
gcc -o calling -L. calling.o -ltest1	//-L后接动态库文件所在目录，-l后接库文件名
./calling
此时出现提示
	./calling: error while loading shared libraries: libtest1.so: cannot open shared object file: No such file or directory。
解决办法
# cp libtest1.so /lib	//将库文件添加到根目录的lib文件夹里
# ldconfig				//往/lib和/usr/lib里面加东西，是不用修改/etc/ld.so.conf的，但是完了之后要调一下ldconfig，不然这个library会找不到。
再执行就可以成功执行了

2、显示调用:调用dlfcn.h里的函数获取动态库里的函数
程序为main1.c
gcc main1.c -o main1 -ldl	//-ldl选项指明生成的对象模块需要使用共享库

