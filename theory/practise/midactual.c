#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int curr = 0;

    pid_t pid1 = fork();

    if (pid1 < 0)
    { // error
        exit(1);
    }
    else if (!pid1)
    { // child 1
        for (int i = 0; i < 5; i++)
        { // loop of 5
            printf("%d ", arr[curr++]);
        }
    }
    else
    { // parent process
        wait(NULL);
        curr += 5;  
        pid_t pid2 = fork(); /// creating another child

        if (pid2 < 0)
        { // error
            exit(1);
        }
        else if (!pid2)
        { // child
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", arr[curr++]);
            }
        }
        else
        { // parent process
            wait(NULL);
            curr += 5;
            for (int i = 0; i < 5; i++)
            {
                printf("%d ", arr[curr++]);
            }

            wait(NULL);
            wait(NULL);
        }
    }

    return 0;
}