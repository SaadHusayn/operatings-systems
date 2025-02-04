#include<stdio.h>
#include<stdlib.h>


int isNumber(char const* const text) {
    if (text == NULL || text[0] == '\0') {
        return 0;
    }

    int dot_counter = 0;
    size_t length = 1;
    for (char character = text[1]; character != '\0';
         ++length, character = text[length]) {
        int const is_valid_character =
            (character >= '0' && character <= '9') ||
            (character == '.' && ++dot_counter == 1);

        if (is_valid_character == 0) {
            return 0;
        }
    }

    char const first_character = text[0];
    int is_character_sign = (first_character == '-' || first_character == '+');
    if ((is_character_sign || first_character == '.') && length == 1) {
        return 0;
    }
    if (length == 2 && is_character_sign && text[1] == '.') {
        return 0;
    }
    return (is_character_sign || first_character == '.') ||
           (first_character >= '0' && first_character <= '9');
}

void sort(int *temp, int n){
    int tmp;

    for(int i=0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            if(temp[j+1]<temp[j]){
                tmp = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = tmp;
            }
        }
    }
}

void display(int *temp, int n){
    for(int i=0;i<n;i++){
        printf("%d ",temp[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]){
    if(argc != 1){
        int *temp  = (int *)malloc((argc-1)*sizeof(int));
        for(int i=1;i<argc;i++){
            if(isNumber(argv[i])){
                temp[i-1] = atoi(argv[i]);
            }else{
                printf("Invalid numbers...\n");
                exit(1);
            }
        }
        sort(temp, argc-1);
        display(temp, argc-1);
    }else{
        printf("No numbers given");
    }
    return 0;
}