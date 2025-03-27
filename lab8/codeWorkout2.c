#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

volatile int counter = 0;

void * runner(void *arguments){
    printf("%s: begin\n", (char *)arguments);
    int i;
    
    // int counter = 0;
    for(int i=0;i<1e7;i++){
        counter ++;
    }
    
    printf("%s: done, counter=%d\n", (char *)arguments, counter);


    return NULL;
}

int main(int argc, char *argv[]){
    pthread_t p1, p2;

    printf("main: begin (counter=%d)\n", counter);


    pthread_create(&p1,NULL,runner,"A");
    pthread_create(&p2,NULL,runner,"B");


    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("main: done with both(counter=%d)\n", counter);

    return 0;
}