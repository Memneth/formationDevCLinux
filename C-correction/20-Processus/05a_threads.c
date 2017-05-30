// 06a_threads.c
// Partage d'une variable entre threads du meme processus

#include <stdio.h>
#include <stdlib.h>
#include </usr/include/pthread.h>

int i;

void somme(void)
{
    i += 10;
    printf("Fils %d\n",i);
    i += 20;
    printf("Fils %d\n",i);
}

int main(void)
{
     pthread_t num_thread;
     
     i = 0;
     
     if(pthread_create(&num_thread, NULL, (void *(*)())somme, NULL) == -1)
       perror("Problème pthread_create\n");
     
     i += 1000;
     printf("Père %d\n", i);
     i += 2000;
     printf("Père %d\n", i);
     
     pthread_join(num_thread, NULL);
     
     return 0;
}
