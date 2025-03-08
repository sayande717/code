#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>

// variables
sem_t wrt;
pthread_mutex_t mutex;
int cnt = 1;
int numreader = 0;

void *writer(void *wno)
{   
    sem_wait(&wrt);
    cnt = cnt*2;
    printf("Writer %d modified count to %d\n",(*((int*)wno)),cnt);
    sem_post(&wrt);

}
void *reader(void *rno)
{   
    pthread_mutex_lock(&mutex);
    numreader++;
    if(numreader == 1) {
    }
    pthread_mutex_unlock(&mutex);
    printf("Reader %d: read count as %d\n",*((int*)rno),cnt);

    pthread_mutex_lock(&mutex);
    numreader--;
    if(numreader == 0) {
    }
    pthread_mutex_unlock(&mutex);
}

int main() { 
    int reads, writes,totalOperations;
    printf("Enter the number of reads: "); scanf("%d",&reads);
    printf("Enter the number of writes: "); scanf("%d",&writes);
    totalOperations = (reads+writes);
    pthread_t read[reads],write[writes];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&wrt,0,1);
    int *a = (int*)malloc(sizeof(int)*totalOperations);
    for(int index=1;index<=totalOperations;index++) {
        a[index] = index;
    }
    for(int index = 0; index < reads; index++) {
        pthread_create(&read[index], NULL, (void *)reader, (void *)&a[index]);
    }
    for(int index = 0; index < writes; index++) {
        pthread_create(&write[index], NULL, (void *)writer, (void *)&a[index]);
    }

    for(int index = 0; index < reads; index++) {
        pthread_join(read[index], NULL);
    }
    for(int index = 0; index < writes; index++) {
        pthread_join(write[index], NULL);
    }

    pthread_mutex_destroy(&mutex);
    sem_destroy(&wrt);

    free(a);
    printf("\n");
    return EXIT_SUCCESS;
}
