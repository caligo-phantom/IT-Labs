// Write a C program to solve the readers and writers Problem.
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int num_readers = 0;
sem_t mutex, write_lock;

void *reader(void *arg) {
    int id = *(int*)arg;
    while(1) {
        sem_wait(&mutex);
        num_readers++;
        if(num_readers == 1) {
            sem_wait(&write_lock);
        }
        sem_post(&mutex);

        printf("Reader %d is reading from buffer: ", id);
        for(int i = 0; i < BUFFER_SIZE; i++) {
            printf("%d ", buffer[i]);
        }
        printf("\n");

        sem_wait(&mutex);
        num_readers--;
        if(num_readers == 0) {
            sem_post(&write_lock);
        }
        sem_post(&mutex);
    }
}

void *writer(void *arg) {
    int id = *(int*)arg;

    while(1) {
        sem_wait(&write_lock);

        printf("Writer %d is writing to buffer\n", id);
        for(int i = 0; i < BUFFER_SIZE; i++) {
            buffer[i] = id;
        }

        sem_post(&write_lock);
    }
}

int main() {
    pthread_t threads[6];
    sem_init(&mutex, 0, 1);
    sem_init(&write_lock, 0, 1);

    for(int i = 0; i < 3; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&threads[i], NULL, reader, id);
    }

    for(int i = 0; i < 3; i++) {
        int *id = malloc(sizeof(int));
        *id = i + 1;
        pthread_create(&threads[i + 3], NULL, writer, id);
    }

    for(int i = 0; i < 6; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}