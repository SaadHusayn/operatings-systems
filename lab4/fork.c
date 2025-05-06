#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t pid1;
    pid1 = fork(); // Creating a new process

    if (pid1 < 0)
    {
        printf("Fork1 failed!\n");
        exit(1);
    }
    else if (pid1 == 0)
    {
        printf("Child process1, of  PID: %d\n", getpid());
        // pid_t pp = fork();
        // if (pp < 0)
        //     printf("error");
        // else if (pp == 0)
        // {
        //     printf("babar ");
        //     exit(0);
        // }
        // else
        //     printf("azam");
    }
    else
    {
        // long long int sum = 0;
        // for (int i = 0; i < 1000000; i++)
        //     sum += i;
        printf("Parent process1, of PID: %d\n", getpid());
    }

    // pid_t pid2;
    // pid2 = fork(); // Creating a new process

    // if (pid2 < 0) {
    //     printf("Fork1 failed!\n");
    //     exit(1);
    // }
    // else if (pid2 == 0) {
    //     printf("Child process2, of  PID: %d\n", getpid());
    // }
    // else {
    //     printf("Parent process2, of PID: %d\n", getpid());
    // }

    return 0;
}
