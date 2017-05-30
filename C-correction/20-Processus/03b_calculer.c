//03b_calculer.c

#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[])
{
    int sum;
    
    if(argc != 3)
    {
        printf("Erreur !\n");
        exit(1);
    }
    
    sum = atoi(argv[1]) + atoi(argv[2]);
    printf("La somme est %d\n",sum);
    exit(0);
}
