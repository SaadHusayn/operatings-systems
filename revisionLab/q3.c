#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t mutex;
#define FILENAME "shared_file.txt"

void *thread_func(void *args)
{
    pthread_mutex_lock(&mutex);
    int i = *((int *)args);
    FILE *fptr;

    if (i == 0)
    {
        // write helloworld to file
        printf("in a thread, writing hello world to the file\n");
        fptr = fopen(FILENAME, "w");

        fprintf(fptr, "helloworld\n");
    }
    else if (i == 1)
    {
        // reading from a file
        printf("in a thread, reading from the file\n");
        fptr = fopen(FILENAME, "r");

        char buffer[256];

        while (fgets(buffer, sizeof(buffer), fptr) != NULL)
        {
            printf("%s", buffer);
        }
    }
    else
    {
        // write helloworld to file
        printf("in a thread, appending abcdefg to the file\n");
        fptr = fopen(FILENAME, "a");

        fprintf(fptr, "abcdefg\n");
    }
    fclose(fptr);
    pthread_mutex_unlock(&mutex);

    return NULL;
}

int main()
{
    pthread_mutex_init(&mutex, NULL);
    FILE *fptr = fopen(FILENAME, "r");
    char buffer[256];

    printf("Initially the content of file is : \n");
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fptr);

    pthread_t threads[3];
    int thread_args[3];

    for (int i = 0; i < 3; i++)
    {
        thread_args[i] = i;
        pthread_create(&threads[i], NULL, thread_func, (void *)&thread_args[i]);
    }

    char *string_to_write = "helloworld";
    for (int i = 0; i < 3; i++)
        pthread_join(threads[i], NULL);

    fptr = fopen(FILENAME, "r");

    printf("Finally the content of file is : \n");
    while (fgets(buffer, sizeof(buffer), fptr) != NULL)
    {
        printf("%s", buffer);
    }

    fclose(fptr);
    pthread_mutex_destroy(&mutex);
    return 0;
}