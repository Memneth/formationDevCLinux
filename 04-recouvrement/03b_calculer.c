/*
 * 03b_calculer.c
 *
 * gcc -o calculer  03b_calculer.c

 *
 *
 */


#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int i;
    int j;
    int sum;

    if(argc!=3){
        printf("Erreur");
        exit(1);
    }
        i = atoi (argv[1]);
        j = atoi (argv[2]);
        sum = i+j;
        printf("la somme est égale à %d\n",sum);
        exit(0);

}

