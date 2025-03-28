#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 2
int flag[NUM_THREADS];
int turn;

void* peterson_algorithm(void* arg) {
    int id = *(int*)arg;
    for (int i = 0; i < 5; i++) {
        flag[id] = 1;
        turn = 1 - id;
        while (flag[1 - id] && turn == 1 - id) {
        }
        printf("Thread %d is in the critical section\n", id);
        flag[id] = 0;
    }
    return NULL;
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS] = {0, 1};
    flag[0] = flag[1] = 0;
    turn = 0;

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, peterson_algorithm, &thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}

