
#include <stdio.h>   
#include <stdlib.h>  
#include <unistd.h>  
#include <sys/wait.h>  // wait() header file
#include<time.h>    
int main() {
    srand(time(NULL));
    pid_t pid = fork();  // fork() creating child process

    if (pid < 0) {  //  parent process 
        printf("error \n");
        exit(1);
    } 
    else if (pid == 0) {  // child process 
        
        printf("child process PID: %d\n", getpid());  // this line not executed.
    } 
    else {  //parent

        pid_t pid2 = fork();
        if(pid2 < 0){
            printf("fork failed! \n");
            exit(1);
        }else if(pid2 == 0){
            printf("Second child process PPID: %d\n", getppid());
            printf("Random num: %d\n", rand() % 100 + 1);
        }else{
            wait(NULL);
            printf("ALl child processes completed!");
        }
    }
    return 0;
}