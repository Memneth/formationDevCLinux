// 01a_select.c
// Compilation :

#include <sys/time.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

void main(void)
{
	fd_set readset;
	struct timeval duree;
	char c;
	int fd,retour;

	fd=0;
	FD_ZERO(&readset);
	FD_SET(fd, &readset);

	duree.tv_sec=10;
	duree.tv_usec=0;

	retour=select(1, &readset, NULL, NULL, &duree);

	if(retour ==0)
		printf("Fin de temporisation. Pas de caractères reçus !\n");
	else if (FD_ISSET(fd, &readset))
	{
		read(fd, &c, sizeof(c));
		printf("Caractère lu : %c\n", c);
	}
}
