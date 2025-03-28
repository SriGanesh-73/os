#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

pthread_mutex_t lock;

void* print_count(void* thread_id) {
    long tid = (long) thread_id;

    pthread_mutex_lock(&lock);
    printf("Thread %ld is running\n", tid);
    pthread_mutex_unlock(&lock);

    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    long t;

    pthread_mutex_init(&lock, NULL);

    for (t = 0; t < NUM_THREADS; t++) {
        if (pthread_create(&threads[t], NULL, print_count, (void*)t)) {
            printf("Error: Unable to create thread %ld\n", t);
            exit(-1);
        }
    }

    for (t = 0; t < NUM_THREADS; t++) {
        pthread_join(threads[t], NULL);
    }

    pthread_mutex_destroy(&lock);

    printf("Main: All threads have finished.\n");
    return 0;
}

