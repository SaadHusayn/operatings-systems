#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define ARRAY_SIZE 10000000
#define NUM_THREADS 10

float A[ARRAY_SIZE];
float B[ARRAY_SIZE];
float C[ARRAY_SIZE];

void * thread_function(void *args){
    int threadNo = *((int *)args);
    int start = threadNo * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    for(int i=start;i<end;i++) C[i] = A[i] + B[i];

    return NULL;
}

void initialize_arrays(){
    for(int i=0;i<ARRAY_SIZE;i++){
        A[i] = i;
        B[i] = 2*i;
        C[i] = 0;
    }
}

int main(){
    pthread_t threads[NUM_THREADS];
    int threads_param[NUM_THREADS];

    initialize_arrays();

    printf("Performing the task parallely with %d worker threads:\n", NUM_THREADS);

    for(int i=0;i<NUM_THREADS;i++){
        threads_param[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void *)&threads_param[i]);
    }

    //joining all the worker threads
    for(int i=0;i<NUM_THREADS;i++){
        pthread_join(threads[i], NULL);
    }

    printf("Done with Performing the task parallely, here are first 10 elements from array C\n");
    for(int i=0;i<10;i++) printf("%.1f ", C[i]);


    return 0;
}