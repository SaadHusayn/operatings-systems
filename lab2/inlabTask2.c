#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 1)
    {
        FILE *fptr;

        fptr = fopen(argv[1], "r");

        if (fptr != NULL)
        {
            char buffer[100];

            while (fgets(buffer, 100, fptr))
            {
                printf("%s", buffer);
            }
        }
        else
        {
            printf("Error opening in File....");
        }

        fclose(fptr);
    }else{
        printf("Error, file is missing\n");
    }

    return 0;
}