#define _XOPEN_SOURCE 700

#include<stdio.h>
#include<signal.h>
#include<stdlib.h>


void sigint_handler(int signum){
    fprintf(stdout, "SIGINT (Ctrl + c) recieved. Terminating...\n");
    exit(signum);
}

int main(){
    //set up signal action structure
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    
    //register the signal handler of SIGINT using sigaction
    if(sigaction(SIGINT, &sa, NULL) == -1){
        perror("sigaction");
        return EXIT_FAILURE;
    }

    while(1) ;


    return EXIT_SUCCESS;
}