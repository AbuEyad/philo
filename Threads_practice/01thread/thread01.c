#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int mails = 0;

void *routine() 
{
    printf("Thread is running\n");
    for(int i = 0; i < 1000000; i++)
    {
        mails++;
    }
    return(NULL);
}

int main(int argc, char *argv[]){
    
    pthread_t p1, p2;
    
    if(pthread_create(&p1, NULL, &routine, NULL) != 0) 
        {return 1;}
    if(pthread_create(&p2, NULL, &routine, NULL) != 0) 
        {return 2;}
    if(pthread_join(p1, NULL) != 0) 
        {return 3;}
    if(pthread_join(p2, NULL) != 0) 
        {return 4;}

    // printf("Number of mails = %d\n", mails);
    return 0;
}

//gcc -S thread01.c ------> procude the assemply file. 