#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<stdlib.h>

#define READ_END 0
#define WRITE_END 1

int main(){
    int fd[2];
    char read_buffer[100];
    char write_buffer1[] = "Hello World\n";
    char write_buffer2[] = "Nice Here";

    if(pipe(fd) == -1){
        fprintf(stderr, "pipe not created");
        exit(1);
    }

    pid_t pid = fork();

    if(pid == 0){
        close(fd[WRITE_END]);
        while(1){
            int bytes_read = read(fd[READ_END], read_buffer, sizeof(read_buffer));
            if(bytes_read < 0){
                fprintf(stderr, "error reading from file\n");
                exit(1);
            } else if(bytes_read == 0){
                // Pipe is closed, no more data
                break;
            } else {
                printf("%s", read_buffer);
            }
        }
        close(fd[READ_END]);

        
    }else if(pid > 0){
        close(fd[READ_END]);
        int bytes_written = write(fd[WRITE_END], write_buffer1, strlen(write_buffer1) + 1);

        sleep(3);

        bytes_written = write(fd[WRITE_END], write_buffer2, strlen(write_buffer2) + 1);

        close(fd[WRITE_END]);
    }
}