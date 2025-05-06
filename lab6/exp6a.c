#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1

//read() is waiting for pipe to be filled, yes read() is waiting for the other process to complete(whether it is parent or child) and then it is executing after commands

int main(void){
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    if(pipe(fd) == -1){//if creating pipe is unsuccessfull
        fprintf(stderr, "Pipe Failed");
        exit(1);
    }

    pid = fork();
    if(pid < 0){//error occurred
        fprintf(stderr, "Fork Failed");
        exit(1);
    }else if(pid > 0){//parent process
        close(fd[READ_END]);
        scanf("%s", write_msg);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[READ_END]);    
        printf("Parent Process ID: %d\n", getpid());
    }else{ //child process
        close(fd[WRITE_END]); //close the unused end of the pipe
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("read: %s\n", read_msg);
        close(fd[READ_END]); //close the read end of the file
        printf("Child Process ID: %d\n", getpid());
    }

    return 0;
}