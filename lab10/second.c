#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#define BUFFER_SIZE 5

sem_t mutex, empty, full;
int buffer[BUFFER_SIZE];
int in = 0, out = 0;


void* producer(void* arg) {
    int item;
    for(int i=0;i<5;i++) {
        item = rand() % 100; // generate random item
        sem_wait(&empty);      // wait for emty space in buffer
        sem_wait(&mutex);      // lock Critical section
        buffer[in] = item;
        printf("Produced: %d\n", item);
        in = (in + 1) % BUFFER_SIZE;

        sem_post(&mutex);      // Unlock critical section
        sem_post(&full);       // Full slots
        sleep(rand() % 3);     // Random wait to simulate time
    }
}

void* consumer(void* arg) {
    int item;
    for(int i=0;i<5;i++)  {
        sem_wait(&full);       // Wait for full slot
        sem_wait(&mutex);      // Lock for critical section

        item = buffer[out];
        printf("Consumed: %d\n", item);
        out = (out + 1) % BUFFER_SIZE;

        sem_post(&mutex);      // Unlock critical section
        sem_post(&empty);      // full slots
        sleep(rand() % 3);     // Random wait
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    //  initialize  Semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, BUFFER_SIZE);
    sem_init(&full, 0, 0);

    // Threads creation
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // wait for threads
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // destroy Semaphores
    sem_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}