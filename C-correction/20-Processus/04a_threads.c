// 04a_threads.c
// Compilation : gcc 04a_threads.c -o 04a_threads -lpthread

#include <stdio.h>
#include </usr/include/pthread.h>

#define pthread_attr_default NULL

pthread_t pthread_id[3];

void f_thread(int i)
{
     printf("je suis le %dème pthread d'identité %d.%d\n",i,getpid(),pthread_self());
}

int main(void)
{
     int i;

     for(i=0;i<3;i++)
        pthread_create(&pthread_id[i], pthread_attr_default, (void *)f_thread, &i);

     printf("Je suis le thread initial %d.%d\n",getpid(),pthread_self());
     pthread_join(*pthread_id,NULL);

     return(0);
}
