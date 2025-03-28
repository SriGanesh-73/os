#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void* print_hello(void* arg){
	printf("Hello from thread!\n");
	return NULL;
}
int main(){
	pthread_t thread_id;
	if(pthread_create(&thread_id,NULL,print_hello,NULL)){
		fprintf(stderr,"Error in thread creation\n");
		return 1;
	}
	printf("Finalizing thread\n");
	if(pthread_join(thread_id,NULL)){
		fprintf(stderr,"Error in completion");
		return 1;
	}
	printf("Thread was executed successfully\n");
	return 0;
}

