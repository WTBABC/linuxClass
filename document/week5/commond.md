ar -rc libtest1.a fun1.o fun2.o			//生成名为test1的库文件
gcc calling.c -o calling -L. -ltest1		//编译calling.c生成可执行文件，test1库文件和calling.c文件在同一目录，所以-L后直接‘.’， -l后加上库文件名字
gcc main1.c -o main1 -L./test1 -ltest1	//main1.c 和库文件不在同一目录，-L接库文件所在目录，可以用相对路径或绝对路径
