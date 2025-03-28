#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

sem_t sem;

void* critical_section(void* arg) {
    int id = *(int*)arg;
    printf("Thread %d is waiting to enter the critical section...\n", id);
    sem_wait(&sem);
    printf("Thread %d is in the critical section\n", id);
    sleep(1);
    sem_post(&sem);
    printf("Thread %d has left the critical section\n", id);
    return NULL;
}

int main() {
    pthread_t threads[3];
    int thread_ids[3] = {0, 1, 2};
    sem_init(&sem, 0, 1);

    for (int i = 0; i < 3; i++) {
        pthread_create(&threads[i], NULL, critical_section, &thread_ids[i]);
    }

    for (int i = 0; i < 3; i++) {
        pthread_join(threads[i], NULL);
    }

    sem_destroy(&sem);
    return 0;
}

