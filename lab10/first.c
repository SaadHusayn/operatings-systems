#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_THREADS 5

int shared_mem = 0;

pthread_mutex_t mutex;

void * runner(void *args){
    int arg = *((int *)args);

    pthread_mutex_lock(&mutex);

    shared_mem ++ ;

    printf("Thread No. %d, Shared Mem Value:%d\n",arg, shared_mem);


    pthread_mutex_unlock(&mutex);


    return NULL;
}

int main(){
    pthread_t threads[NUM_THREADS];
    int thread_args[NUM_THREADS];
    pthread_mutex_init(&mutex, NULL);


    for(int i=0;i<NUM_THREADS;i++){
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, runner, (void *)&thread_args[i]);
    }

    for(int i=0;i<NUM_THREADS;i++) pthread_join(threads[i], NULL);

    pthread_mutex_destroy(&mutex);
    return 0;
}