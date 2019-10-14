#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>

#define UMAXL 100
#define UMAXN 100
#define TMAXL 10000

int urand();
int usum(int*, int);
void ushow(int*, int);
int compare(const void*, const void*);
void howLongQsort(int*, int);
void howLongMao(int*, int);
void Mysort(int*, int);
void Syssort(int*, int);
