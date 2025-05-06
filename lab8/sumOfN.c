#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum = 0;

void * runner(void *args){
    int upper = *((int *)args);
    if(upper > 0){
        for(int i=1;i<=upper;i++){
            sum += i;
        }
    }

    pthread_exit((void *)(long)(42));
}

int main(int argc, char *argv[]){
    pthread_t threadID;
    pthread_attr_t arguments;
    pthread_attr_init(&arguments);

    if(argc != 2){
        printf("Usage: ./sumOfN <number>\n");
        exit(1);
    }

    int N = atoi(argv[1]);

    int returnValue;

    pthread_create(&threadID, &arguments, runner, (void *)&N);
    pthread_join(threadID, (void **)&returnValue);

    printf("sum=%d\n", sum);
    printf("returnValue=%d\n", returnValue);

    return 0;
}