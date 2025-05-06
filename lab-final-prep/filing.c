#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(){
    char buffer[101];

    int fd = open("src.txt", O_RDONLY);

    if(fd < 0){
        perror("open");
        close(fd);
        exit(1);
    }

    int bytes_read = read(fd, buffer, sizeof(buffer) - 1);
    if(bytes_read < 0){
        perror("read");
        exit(1);
    }else if(bytes_read == 0){
        fprintf(stderr, "file is empty\n");
        close(fd);
        exit(1);
    }

    buffer[bytes_read] = '\0';

    //now writing to the file

    int fd1 = open("dest.txt", O_WRONLY | O_TRUNC | O_CREAT, 0644);

    if(fd1 < 0){
        perror("open");
        exit(1);
    }

    int bytes_written = write(fd1, buffer, bytes_read);

    if(bytes_written < 0){
        perror("write");
        exit(1);
    }

    printf("write to dest.txt successfully\n");
    close(fd);
    close(fd1);

    
    return 0;
}