#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <stdlib.h>
#include <unistd.h>

void proc_exit() {
    int wstat;
    pid_t pid;

    while (1) {
        pid = wait3(&wstat, WNOHANG, NULL);
        if (pid == 0 || pid == -1) {
            fprintf(stdout, "return value of wait3() is %d\n", pid);
            return;
        }
        fprintf(stdout, "Return code: %d\n", wstat);
    }
}

int main() {
    signal(SIGCHLD, proc_exit);

    for (int i = 0; i < 3; i++) {
        switch (fork()) {
            case -1:
                perror("main: fork");
                exit(0);
            case 0:
                printf("Child process %d: I'm alive (temporarily)\n", i + 1);
                int ret_code = rand();
                printf("Child process %d: Return code is %d\n", i + 1, ret_code);
                exit(ret_code);
        }
    }

    sleep(5); // Parent sleeps so children terminate and become zombies
    pause();  // Wait for a signal (SIGCHLD)
    exit(0);
}
