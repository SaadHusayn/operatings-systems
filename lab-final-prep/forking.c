#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<time.h>
#include<stdlib.h>

int main(){
    srand(time(NULL));
    pid_t pid = fork();
    if(pid == 0){
        //child1 
        printf("Child 1: pid : %d\n", getpid());
        exit(0);
    }else if(pid > 0){
        //parent process

        pid_t pid1 = fork();

        if(pid1 < 0){
            perror("fork");
            exit(1);
        }else if(pid1 == 0){
            //child 2
            printf("Child 2: ppid=%d, random no is %d\n", getppid(), rand() % 100);
        }else{
            wait(NULL);
            wait(NULL);
            printf("Parent: All child processes completed\n");
        }
    }
    return 0;
}