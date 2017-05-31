/*
 * 03b_exec.c
 *
 * gcc -o exec 03b_exec.c
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void main()
{

    int i;
    int j;
    int status;
    char  conv1[10];
    char  conv2[10];
    pid_t fils;


    printf("Saisir la valeur de i:");
    scanf("%d",&i);
    printf("Saisir la valeur de j:");
    scanf("%d",&j);

    fils = fork();

    //conversion des int en alpha
    if (fils==0){
        sprintf(conv1,"%d",i);
        sprintf(conv2,"%d",j);
        //recouvrement de la fonction calculer
        execl("./calculer","Calcul", conv1,conv2, NULL);
    }else{
        wait(&status);
    }
}

