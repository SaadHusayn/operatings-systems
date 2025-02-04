#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

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

void readDataFromFile(int *temp, int *n, char filename[]){
    FILE *fptr = fopen(filename, "r");

    if(fptr != NULL){
        char ch;
        while((ch = fgetc(fptr)) != EOF){
            if(isdigit(ch)){
                temp[*n] = (temp[*n] * 10) + (ch - '0');
            }else{
                *n = *n + 1;
            }
        }
    }
}


int main(int argc, char *argv[]){
    if(argc != 1){
        int *temp = (int *)calloc(100, sizeof(int)); //arbitary size of 100, all initialized with zero
        int n = 0;

        readDataFromFile(temp, &n, argv[1]);

        int missingNum = getMissingNum(temp, n);
        printf("The missing num is %d\n", missingNum);

        
    }else{
        printf("No file given");
        exit(1);
    }
    return 0;
}