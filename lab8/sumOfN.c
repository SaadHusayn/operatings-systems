#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int sum = 0;

void * runner(void *arguments){
    int i, upper = *((int *)arguments);
    if(upper > 0){
        for(int i=1;i<=upper;i++){
            sum += i;
        }
    }
    return (void *)(int)42;
}

int main(int argc, char *argv[]){
    pthread_t threadID;
    pthread_attr_t attributes;
    pthread_attr_init(&attributes);

    if(argc != 2){
        printf("Usage: ./sumOfN <number>\n");
        exit(1);
    }

    int N = atoi(argv[1]);

    int returnValue;

    pthread_create(&threadID,&attributes,runner,(void *)&N);
    pthread_join(threadID, (void **)&returnValue);

    printf("sum=%d\n", sum);
    printf("returnValue=%d\n", returnValue);

    return 0;
}