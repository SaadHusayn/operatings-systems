#include<stdio.h>
#include<pthread.h>
#include<unistd.h>

int counter = 10;

void *thread_func(void *args){
    int i = *((int *)args);

    if(i == 0){
        //increment 5 times
        for(int i=0;i<5;i++){
            counter++;
        }
    }else if(i == 1){
        //decrement 5 times
        for(int i=0;i<5;i++){
            counter--;
        }
    }else{
        //multiplies by 2 once
        counter *= 2;
    }

    return NULL;
}

int main(){
    pthread_t threads[3];
    int thread_args[3];

    printf("Initially the value of counter is %d\n", counter);

    for(int i=0;i<3;i++){
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void *)&thread_args[i]);
    }

   for(int i=0;i<3;i++) pthread_join(threads[i], NULL);

   printf("Threads completed their work, now the value of counter is %d\n", counter);
}