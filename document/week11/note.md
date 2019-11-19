1. 6-8.c + init.c
编写了一个守护进程
tail -f /tmp/6-8.log
2. exitTime.c	输出子进程的退出时间
3. pipe.c	父子进程可通过管道传输数据，linux的一个中文不一定占两个字节
4. test1.c	子进程正常退出，而父进程未结束，子进程将变成僵尸进程
5. test2.c	子进程一直运行，可通过 kill -9 子进程的pid 结束此进程
6. test3.c	wait(&s)函数参数为输出型的，
		WIFEXITED(s)的值不为0时，代表子进程正常退出，可以通过WEXITSTATUS(s)获取子进程exit函数传入的参数（退出码）
		WIFSIGNALED(s)的值不为0时，WTERMSIG(s)可获取子进程因信号而中止的信号代码
7. test3_1.c	对wait函数的功能介绍的补充
8. wfile.c	派生两个进程，都向父进程打开的文件写入数据，然后父进程输出文件中的内容，证明进程共享文件指针
