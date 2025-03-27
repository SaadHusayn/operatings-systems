#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

void print_val(int lv)
{
    for (int j = lv; j < lv + 5; j++)
    {
        printf("%d ", arr[j]);
    }
    printf("\n");
}
int main()
{
    //parent process P0 
    int start_index = 0;
    pid_t pid = fork();
    if (pid == 0)
    { // child process P1
        printf("Process : ");
        if (start_index != 0)
            start_index += 5; // Move to the next 5 elements
        print_val(start_index);
        return 0; // exit P1
    }
    else if (pid > 0)
    { // parent process P0
        wait(NULL); // Wait for 1st child process to finish.
        start_index += 5; // Move to the next 5 elements
        printf("Process : ");
        print_val(start_index);
        pid_t pid1 = fork();
        if (pid1 == 0)
        { // P2 - 2nd child of P0
            printf("Process : ");
            if (start_index != 0)
                start_index += 5;
            print_val(start_index);
            return 0; // exit P2
        }
        // else
        // wait (NULL); // shifted below. No error checking.
    }
    else
        return 1; // fprintf(stderr, "Fork failed!\n");

    
    wait(NULL); // Wait for 1st child process to finish.
    wait(NULL); // Wait for 2nd child process to finish.
    return 0;
}


