#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define N 5

typedef enum { THINKING, HUNGRY, EATING } state_t;
state_t state[N];

pthread_mutex_t mutex;
pthread_cond_t cond[N];

void test(int i) {
    if (state[i] == HUNGRY && state[(i + 4) % N] != EATING && state[(i + 1) % N] != EATING) {
        state[i] = EATING;
        pthread_cond_signal(&cond[i]);
    }
}

void take_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = HUNGRY;
    test(i);
    while (state[i] != EATING) {
        pthread_cond_wait(&cond[i], &mutex);
    }
    pthread_mutex_unlock(&mutex);
}

void put_forks(int i) {
    pthread_mutex_lock(&mutex);
    state[i] = THINKING;
    test((i + 4) % N);
    test((i + 1) % N);
    pthread_mutex_unlock(&mutex);
}

void* philosopher(void* num) {
    int i = *(int*)num;
    while (1) {
        printf("Philosopher %d is thinking.\n", i);
        sleep(1);

        printf("Philosopher %d is hungry.\n", i);
        take_forks(i);

        printf("Philosopher %d is eating.\n", i);
        sleep(1);

        // Put down forks
        put_forks(i);
    }
}

int main() {
    pthread_t thread_id[N];
    int phil[N];

    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < N; i++) {
        pthread_cond_init(&cond[i], NULL);
        phil[i] = i;
    }

    for (int i = 0; i < N; i++) {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
    }

    for (int i = 0; i < N; i++) {
        pthread_join(thread_id[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    for (int i = 0; i < N; i++) {
        pthread_cond_destroy(&cond[i]);
    }

    return EXIT_SUCCESS;
}

