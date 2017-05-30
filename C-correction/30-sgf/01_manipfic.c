// 01_manipfic.c
// Compilation : gcc 01_manipfic.c -o 01_manipfic

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

void clrscr(void)
{
    printf("\033[2J\033[1;1H");
}

int main(void)
{
	struct eleve {
		char nom[10];
		int note;
	};

	int fd,i,ret;

	struct eleve un_eleve;

	fd=open("./notes.dat", O_RDWR|O_CREAT,S_IRUSR|S_IWUSR);

	if(fd==-1)
		perror("Problème fonction OPEN");

	clrscr();

	i=0;
	while(i<4)
	{
		printf("Nom élève : ");
		scanf("%s", un_eleve.nom);
		printf("Notes : ");
		scanf("%d", &un_eleve.note);

		write(fd,&un_eleve, sizeof(un_eleve));
		i++;
	}

	ret=lseek(fd,0,SEEK_SET);

	if(ret==-1)
		perror("Problème fonction LSEEK");

	printf("\n\n\nLa nouvelle position est %d.\n\n\n", ret);

	i=0;
	while(i<4)
	{
		read(fd,&un_eleve,sizeof(un_eleve));
		printf("Nom : %s\nNote : %d\n", un_eleve.nom, un_eleve.note);
		i++;
	}

	close(fd);
}
