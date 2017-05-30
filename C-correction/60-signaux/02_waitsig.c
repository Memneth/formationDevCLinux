// 02_waitsig.c

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

void fin_attente()
{
	printf("Signal reçu. Arrêt de la pause.\n");
}

int main(void)
{
	char chaine[10];
	int fp;

	// arme le signal et l'attend
	if(signal(SIGINT, fin_attente) == SIG_ERR)
	{
		perror("Signal");
		exit(1);
	}

	// attente
	pause();

	printf("je vais faire mon travail\n");
	printf("Donnez-moi la chaine attendue\n");
	scanf("%s", chaine);

	fp=open("fichier", O_WRONLY);
	write(fp, chaine, strlen(chaine));
	close(fp);
	exit(0);
}
