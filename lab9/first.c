#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<stdlib.h>

void my_handler(int signum){
    printf("Caught user defined signal SIGUSR1\n now terminating program\n");
    exit(0);
}

//signal handler function
void sigint_handler(int signum){
    fprintf(stdout, "Caught signal SIGINT with %d signum\n", signum);
    if((signal(SIGUSR1, my_handler)) != SIG_ERR){
        kill(getpid(), SIGUSR1);
    }
}

int main(){
    //registering signal handler for SIGINT
    if((signal(SIGINT, sigint_handler)) == SIG_ERR){
        fprintf(stderr, "Error assigning signal handler to SIGINT\n");
    }



    printf("Enter ctrl-c to send a SIGINT signal: ");


    while(1){
        sleep(1);
    }

    return 0;
}