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

int getMissingNum(int *temp, int n){
    int diff = temp[1] - temp[0];
    for(int i=1;i<n;i++){
        if(temp[i] != temp[i-1]+diff){
            return temp[i-1] + diff;
        }
    }
    //if series is correct the missing num will be next num after the last
    return temp[n-1] + diff;
}

void writeInFile(int missingNum){
    FILE *fptr = fopen("postLab2.txt", "w");

    if(fptr != NULL){
        fprintf(fptr, "%d", missingNum);
    }else{
        printf("Error Opening File");
        exit(1);
    }
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
        int missingNum = getMissingNum(temp, argc-1);
        writeInFile(missingNum);
        printf("The missing number is written in the file postLab2.txt\n");
        
    }else{
        printf("No numbers given");
        exit(1);
    }
    return 0;
}