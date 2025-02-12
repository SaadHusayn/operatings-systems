#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;
    pid = fork(); // Creating a new process

    if (pid < 0) {
        printf("Fork failed!\n");
        exit(1);
    }
    else if (pid == 0) {
        printf("Child process, of  PID: %d\n", getpid());
    }
    else {
        printf("Parent process, of PID: %d\n", getpid());
    }
    return 0;
}
