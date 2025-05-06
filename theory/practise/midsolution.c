#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
int start_index = 0;

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

    pid_t pid = fork();
    if (pid == 0)
    {
        printf("Process : ");
        if (start_index != 0)
            start_index += 5;
        print_val(start_index);
        return 0;
    }
    else if (pid > 0)
    {
        printf("Process : ");
        if (start_index != 0)
            start_index += 5;
        print_val(start_index);
        pid_t pid1 = fork();
        if (pid == 0)
        {
            printf("Process : ");
            if (start_index != 0)
                start_index += 5;
            print_val(start_index);
            return 0;
        }
    }
    else
    {
        return 1;
    }

    wait(NULL);
    wait(NULL);
    return 0;
}