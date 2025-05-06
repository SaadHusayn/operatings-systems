#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(int *arr, int size){
    int temp;
    for(int i=0;i<size-1;i++){
        for(int j=0;j<size-i-1;j++){
            if(arr[j+1] < arr[j]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(int argc, char *argv[]){
    int *arr =  (int *)malloc((argc-1) * sizeof(int));
    for(int i=1;i<argc;i++){
        arr[i-1] = atoi(argv[i]);
    }

    sort(arr, argc-1);

    for(int i=0;i<argc-1;i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}