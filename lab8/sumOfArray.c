#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

#define NUM_THREADS 10
#define ARRAY_SIZE 1000000

int array[ARRAY_SIZE];

void initialize_array(){
    for(int i=0;i<ARRAY_SIZE;i++){
        array[i] = i;
    }
}

void * mythread(void *args){
    int threadid = *((int *)args);
    printf("%d\n", threadid);
    int start = threadid * (ARRAY_SIZE / NUM_THREADS);
    int end = start + (ARRAY_SIZE / NUM_THREADS);

    int sum = 0; // local sum

    for(int i=start ; i<end ;i++){
        sum += array[i];
    }
    

    return (void *)(long)sum;

}

int main(){
    pthread_t my_threads[NUM_THREADS];
    int thread_results[NUM_THREADS];
    int thread_params[NUM_THREADS];
    int final_sum = 0;

    initialize_array();

    for(int i=0;i<NUM_THREADS;i++){
        thread_params[i] = i;
        pthread_create(&my_threads[i], NULL, mythread, (void *)&thread_params[i]);
    }

    //joining all the threads
    for(int i=0;i<NUM_THREADS;i++){
        pthread_join(my_threads[i], (void **)&thread_results[i]);
        printf("sum from thread%d=%d\n", i+1, (int)thread_results[i]);
        final_sum += (int)thread_results[i];
    }

    if(ARRAY_SIZE % NUM_THREADS != 0){//all elements of array have not summed by threads, then main threads will sum the remaining
        int start = (NUM_THREADS) * (ARRAY_SIZE / NUM_THREADS);
        int end = ARRAY_SIZE;

        for(int i=start;i<end;i++){
            final_sum += array[i];
        }
    }

    

    printf("Final sum=%d", final_sum);
    return 0;
}