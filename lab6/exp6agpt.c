#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 25
#define READ_END 0
#define WRITE_END 1



int main(void) {
    char write_msg[BUFFER_SIZE];
    char read_msg[BUFFER_SIZE];

    int fd[2];
    pid_t pid;

    if (pipe(fd) == -1) { // if creating pipe is unsuccessful
        fprintf(stderr, "Pipe Failed");
        exit(1);
    }

    pid = fork();
    if (pid < 0) { // error occurred
        fprintf(stderr, "Fork Failed");
        exit(1);
    } else if (pid == 0) { // child process
        close(fd[WRITE_END]); // close the unused write end of the pipe
        printf("Child Process waiting for data...\n");
        read(fd[READ_END], read_msg, BUFFER_SIZE);
        printf("Child received: %s\n", read_msg);
        close(fd[READ_END]); // close the read end of the pipe
        printf("Child Process ID: %d\n", getpid());
    } else { // parent process
        sleep(1); // ensure child runs first
        close(fd[READ_END]); // close the unused read end of the pipe
        printf("Enter a message: ");
        fgets(write_msg, BUFFER_SIZE, stdin);
        write(fd[WRITE_END], write_msg, strlen(write_msg) + 1);
        close(fd[WRITE_END]); // close the write end of the pipe
        printf("Parent Process ID: %d\n", getpid());
    }

    return 0;
}
