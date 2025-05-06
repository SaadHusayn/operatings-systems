#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<errno.h>
#include<stdlib.h>

int main(){
    char cwd[1024];
    pid_t pid = fork();
    if(pid == 0){
        int error_code = execlp("./executable", "./executable", NULL);
        printf("%d\n", error_code);
    }else if(pid > 0){
        system("cat first.s | less");
    }
        
    return 0;
}
