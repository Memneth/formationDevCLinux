#include <stdio.h>
#include <stdlib.h>

void main(void)
{

	char * pointeur = malloc(20 * sizeof(char)); //Allocation de 20 octets

	if(pointeur == NULL)
	{	
    		printf("L'allocation n'a pu être réalisée\n");
	}
	else
	{
    		printf("L'allocation a été un succès\n");

		//Libération des 20 octets précédemment alloués
    		//free(pointeur); 

    		pointeur = NULL; // Invalidation du pointeur
	}
}
