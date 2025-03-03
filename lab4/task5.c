#include<stdio.h>
#include<unistd.h>

int main(){
    for(int i=1;i<=5;i++){
        sleep(1);
        printf("message %d\n", i);
    }
    printf("Execution terminated successfully\n");
}