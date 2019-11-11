test.c: 在调用main函数前可用before_main函数进行准备工作, __attribute__((constructor))+函数名，该函数为构造函数，在调用main函数前调用
														 __attribute__((destructor))+函数名，该函数为析构函数，在程序正常结束前调用
test1.c
caller1.c: 在


fork1.c: 父子进程各自运行，共享变量地址，但不共享变量的值



callback1.c / callback2.c: 
	atexit函数注册回调函数，在main函数 正常 结束后运行,并且调用的顺序与注册的顺序相反


valgrind --track-fds=yes --leak-check=full --undef-value-errors=yes ./+可执行文件

evn 2>err.dat		// '2>'+文件名，出错信息输出到该文件中
