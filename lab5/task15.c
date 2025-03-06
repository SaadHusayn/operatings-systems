#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<sys/wait.h>
int main(){
    int fd;
    fd = open("input.txt", O_RDONLY);
    if(fd == -1){
        perror("open");
        exit(1);
    }

    char buffer[BUFSIZ];

    int bytes_read = read(fd, buffer, BUFSIZ - 1);
    if(bytes_read == -1){
        perror("read");
        close(fd);
        exit(1);
    }

    buffer[bytes_read] = '\0';
    close(fd);
    pid_t pid = fork();

    if(pid<0){
        perror("fork");
        exit(1);
    }else if(pid == 0){//child process
        fd = open("input.txt", O_APPEND | O_WRONLY);
        if(fd == -1){
            perror("open");
            exit(1);
        }

        const char *msg = "\nProcessed by child Process\n";
        
        int bytes_written = write(fd, msg, strlen(msg));
        if(bytes_written == -1){
            perror("write");
            close(fd);
            exit(1);
        }

        close(fd);

        execlp("cat", "cat", "input.txt", NULL);

    }else{//parent process
        
        wait(NULL);

        printf("child process work is completed, terminating...");
    }
}