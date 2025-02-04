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

int ArraySum(int *temp, int n){
    int sum = 0;
    for(int i=0;i<n;i++) sum += temp[i];
    return sum;
}

float ArrayAverage(int *temp, int n){
    float avg = ArraySum(temp, n)*1.0/n;
    return avg;
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
        printf("The sum is %d and the average is %.2f", ArraySum(temp, argc-1), ArrayAverage(temp, argc-1));
    }else{
        printf("No numbers given");
        exit(1);
    }
    return 0;
}