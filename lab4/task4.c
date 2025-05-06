

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> 

int main()
{
    pid_t pid = fork();

    if (pid > 0)
    { 
        printf("Parent: Waiting for child to finish...\n");
        wait(NULL);
        printf("Parent: Child process finished, now parent exiting.\n");
    }
    else if (pid == 0)
    { 
        printf("Child: Executing 'ls -l' command using exec()...\n");
        execlp("ls", "ls", "-l", NULL);                                
        printf("This will not be printed if exec() is successful!\n"); 
    }
    else
    { 
        printf("Fork failed!\n");
    }

    printf("Child process has finished listing the directory.");
    return 0;
}
