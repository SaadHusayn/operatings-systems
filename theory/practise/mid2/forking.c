#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include<wait.h>
#include<stdlib.h>

int main(){
    pid_t pid = fork();
    if(pid < 0){
        fprintf(stderr, "FORK FAILED");
        exit(1);
    }else if(pid == 0){
        execlp("./demo", "demo", NULL);
    }else{
        wait(NULL);
        printf("DONE");
    }
    return 0;
}