#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){
    pid_t pid1, pid2, pid3;
    printf("%d\n", pid3);

    pid1 = fork();
    pid2 = fork();

    if(pid1 == 0){
        printf("A, pid = %d\n", getpid());
    }else{
        pid3 = fork();
        printf("B, pid = %d\n", getpid());
    }

    if(pid2 != 0 && pid3 != 0){
        printf("C, pid = %d\n", getpid());
    }
}