/*
 * 04a_threads.c
 *
 * gcc 04a_threads.c -o thread -lpthread
 *
 *
 */


#include <stdio.h>
#include </usr/include/pthread.h>
//déclaration de la constante
#define pthread_attr_default NULL

pthread_t pthread_id[3];

void f_thread(int i)
{
    printf("je suis le %d ème pthread d'identité %d .%d \n",i,getpid(),pthread_self());
}

int main(void)
{
    int i;
    for(i=0;i<3;i++)
    {
        pthread_create(&pthread_id[i], pthread_attr_default, (void *) f_thread, &i);
    }
    printf("je suis le thread initial d'identité %d .%d \n",getpid(),pthread_self());
    pthread_join (*pthread_id,NULL);

    return 0;
}

