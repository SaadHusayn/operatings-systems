#include<stdio.h>
#include<unistd.h>
#define READ_END 0
#define WRITE_END 1
int main(){

    int fd[2]; //for the ends of the pipes

    if(pipe(fd) == -1){
        fprintf(stderr, "Error piping");
        exit(1);
    }
}