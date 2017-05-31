/*
 * 04b_threads.c
 *
 *fonction print_message(message) sans retour
 * afficher la variable message
 * fin fonction
 *
 * fonction main sans passage d'argument avec code retour
 * declarer message1 Thread1
 * declarer message2 Thread2
 *
 * créer un thread pour lancer print_message avec argument message 1
 * créer un thread pour lancer print_message avec argument message 2
 * appel de pthread_join pour chaque thread
 * afficher la valeur de retour de chaque thread
 *
 * valeur de code de retour =0
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include </usr/include/pthread.h>

#define pthread_attr_default NULL


void *print_message(void *ptr)
{
    char  *message;
    message = (char *) ptr;
    printf("%s\n",message);
}

int main(void)
{
     pthread_t thread1,thread2;
     char message1[] = "Thread1";
     char message2[] = "Thread2";

      int p1 =pthread_create(&thread1, pthread_attr_default, print_message,( void *) message1);
     int p2=pthread_create(&thread2, pthread_attr_default, print_message, ( void *) message2);
     pthread_join (thread1,NULL);
     printf("%d\n",p1);
     pthread_join (thread2,NULL);
    printf("%d\n",p2);
    return 0;
}

