
#include <stdio.h>    
#include <fcntl.h>    
#include <unistd.h>  
#include<string.h> 

int main() {
    int fd1, fd2;  
    char buffer[101];  


    fd1 = open("source.txt", O_RDONLY);
    if (fd1 < 0) {
        printf("Error opening source.txt\n");
        return 1;
    }

    int bytes_read = read(fd1, buffer, sizeof(buffer) - 1);  
    if (bytes_read < 0) {
        printf("Error reading file\n");
        close(fd1);
        return 1;
    }
    if (bytes_read == 0) {
        printf("File is empty.\n");
        close(fd1);
        return 1;
    }
    buffer[bytes_read] = '\0';  

    fd2 = open("destination.txt", O_WRONLY | O_CREAT );
    if (fd2 < 0) {
        printf("Error opening destination.txt\n");
        close(fd1);
        return 1;
    }

    for(int i=0;i<strlen(buffer)/2;i++){
        char tmp  = buffer[i];
        buffer[i] = buffer[strlen(buffer) - i - 1];
        buffer[strlen(buffer) - i - 1] = tmp;
    }


    int bytes_written = write(fd2, buffer, bytes_read);
    if (bytes_written < 0) {
        printf("Error writing to destination.txt\n");
        close(fd1);
        close(fd2);
        return 1;
    }

    close(fd1);
    close(fd2);

    printf("File copied successfully!\n");
    return 0;
}