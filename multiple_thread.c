#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#define N 5
void* print_hello(void* arg){
	int* tid = arg;
	printf("Hello this is from Thread %d\n",*tid);
	return NULL;
}
int main(){
	pthread_t thread_id[N];
	for(int i=0;i<N;i++){
		int tid = i;
		if(pthread_create(&thread_id[i],NULL,print_hello,&tid)){
			fprintf(stderr,"Error in Thread creation\n");
			return 1;
		}
	        if(pthread_join(thread_id[i],NULL)){
                        fprintf(stderr,"Error in Thread joining\n");
                        return 1;
                }
	
	}
	return 0;
}
