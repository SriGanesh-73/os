#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	fork();
	fork();
	fork();
	printf("PID:%d\n",getpid());
	return 0;
}

