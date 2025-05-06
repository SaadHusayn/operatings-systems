#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<limits.h>

typedef struct myArray{
    int *array;
    int size;
} myArray;

void *get_average(void *args){
    myArray arr = *((myArray *) args);

    int average = 0;
    for(int i=0;i<arr.size;i++){
        average += arr.array[i];
    }

    average/=arr.size;

    return (void *)(long)average;
}

void *get_minimum(void *args){
    myArray arr = *((myArray *) args);

    int mini = INT_MAX;
    for(int i=0;i<arr.size;i++){
        if(arr.array[i] < mini) mini = arr.array[i];
    }

    return (void *)(long)mini;
}

void *get_maximum(void *args){
    myArray arr = *((myArray *) args);

    int maxi = INT_MIN;
    for(int i=0;i<arr.size;i++){
        if(arr.array[i] > maxi) maxi = arr.array[i];
    }

    return (void *)(long)maxi;
}

int main(int argc, char *argv[]){

    if(argc == 1){
        fprintf(stderr, "Usage: %s <numbers>\n", argv[0]);
        exit(1);
    }

    myArray arr;
    arr.size = argc - 1;
    arr.array = (int *)calloc(arr.size, sizeof(int));

    for(int i=0;i<arr.size;i++){
        arr.array[i] = atoi(argv[i+1]);
    }

    pthread_t avg_thread, mini_thread, maxi_thread;
    int avg, mini, maxi;

    pthread_create(&avg_thread, NULL, get_average, (void *)&arr);
    pthread_create(&mini_thread, NULL, get_minimum, (void *)&arr);
    pthread_create(&maxi_thread, NULL, get_maximum, (void *)&arr);

    //joining all threads
    pthread_join(avg_thread, (void **)&avg);
    pthread_join(mini_thread, (void **)&mini);
    pthread_join(maxi_thread, (void **)&maxi);

    printf("The average value is %d\nThe minimum value if %d\nThe maximum value is %d\n", avg, mini, maxi);

    return 0;
}