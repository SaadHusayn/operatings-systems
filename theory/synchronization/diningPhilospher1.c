#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5 // Number of philosophers

pthread_mutex_t forks[N]; // Mutex locks for each fork

void *philosopher(void *arg)
{
    int id = *(int *)arg;
    int left = id;            // Left fork index
    int right = (id + 1) % N; // Right fork index

    while (1)
    {
        printf("Philosopher %d is thinking...\n", id);
        sleep(1); // Simulate thinking

        if (id % 2 == 0)
        {
            // Pick up right fork
            pthread_mutex_lock(&forks[right]);
            printf("Philosopher %d picked up right fork %d.\n", id, right);

            // Pick up left fork
            pthread_mutex_lock(&forks[left]);
            printf("Philosopher %d picked up left fork %d and is eating.\n", id, left);
        }
        else
        {
            // Pick up left fork
            pthread_mutex_lock(&forks[left]);
            printf("Philosopher %d picked up left fork %d.\n", id, left);

            // Pick up right fork
            pthread_mutex_lock(&forks[right]);
            printf("Philosopher %d picked up right fork %d and is eating.\n", id, right);
        }

        sleep(2); // Simulate eating

        // Put down forks
        pthread_mutex_unlock(&forks[left]);
        pthread_mutex_unlock(&forks[right]);
        printf("Philosopher %d put down forks and is thinking again.\n", id);
    }
}

int main()
{
    pthread_t philosophers[N];
    int ids[N];

    // Initialize forks (mutexes)
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_init(&forks[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < N; i++)
    {
        ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &ids[i]);
    }

    // Join threads (never actually reaches here)
    for (int i = 0; i < N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes (not reached)
    for (int i = 0; i < N; i++)
    {
        pthread_mutex_destroy(&forks[i]);
    }

    return 0;
}
