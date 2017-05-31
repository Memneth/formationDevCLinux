/*
 * 04c_threads.c
 *
 * Copyright 2017 bob <bob@dev>
 *
 * fonction somme sans argument et sortie
 * i+=10 et afficher Fils et la valeur de i
 * i+=20 et afficher Fils et la valeur de i
 * fin fonction
 *
 * fonction main sans passage d'arguments et avec code retour
 * déclaration de variables nécessaires
 * créer 1 thread pour lancer la fonction somme
 * i+=1000 et afficher père et la valeur de i
 * i+=2000 et afficher père et la valeur de i
 * appel de la fonction pthread_join
 * valeur du code de retour =0
 * fin fonction main
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include </usr/include/pthread.h>
 int i;
/* pthread_create
 * need to pass as third argument a function
 * (that returns void* and accept 1 argument of type void*)
 * */
 void *somme(void *param )
 {
    i+= 10;
    printf("Fils et la valeur de i :%d\n",i);
    i+= 20;
    printf("Fils et la valeur de i :%d\n",i);
}
//test d'une fonction pointeur
void *toto( int *p){
    printf("affichage de la valeur  :%d\n",*p);
    }


int main()
{
    int p1;
    i=0;
    pthread_t thread1;
    p1 = pthread_create(&thread1, NULL, somme, NULL);

    // suivant l'endroit ou est placé le join, le thread se déclenche et se cloture
    pthread_join(thread1, NULL);
    i+= 10000;
    printf("Père et la valeur de i :%d\n",i);
    i+= 20000;
    printf("Père et la valeur de i :%d\n",i);
    //pthread_join(thread1, NULL);

    //appel d'une fonction toto et passage par référence
    int q = 12;
    toto(&q);
    //-------------------------------------------------
    return 0;
}

