// concurrency demo

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

volatile long int a = 0;

volatile long int b = 0;
volatile long int c = 0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void threadFunc(void *arg)
{
    int i;
    // long int localA = 0;

    for (i = 1; i < 500000; i++)
    {
        b = b + i;
    }

}

void threadFunc2(void *arg)
{
    int i;
    // long int localA = 0;

    for (i = 500000; i <= 1000000; i++)
    {
        c = c + i;
    }

}

int main(int argc, char *argv[])
{
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, (void *)threadFunc, NULL);
    pthread_create(&thread2, NULL, (void *)threadFunc2, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    a = b + c;
    printf("a = %ld\n", a);
}