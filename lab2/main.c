#include<stdio.h>

int main(int argc, char *arg[]){
	printf("hello world");
	for(int i=0;i<argc;i++){
	printf("%s ", arg[i]);
}
	return 0;
}
