// communication birectionnelle (tube anonyme) entre un père et un fils
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int p1[2], p2[2], status;
    pid_t idfils;
    char rep[7], mesg[5];

    if(pipe(p1))    {
        perror("Erreur tube 1");
        exit(1);
    }

    if(pipe(p2))    {
        perror("Erreur tube 2");
        exit(2);
    }

    if((idfils = fork()) == -1)    {
        perror("Erreur FORK");
        exit(3);
    }

    if(idfils)     {
        // 1er tube : père vers fils
        close(p1[0]); // Fermé en lecture

        // 2ème tube : fils vers père
        close(p2[1]); // Fermé en écriture

        // Envoie message au fils via tube 1
        if(write(p1[1],"Hello",5) != 5)         {
            fprintf(stderr,"père : erreur en écriture !\n");
            exit(4);
        }

        // Attente réponse du fils via tube 2
        if(read(p2[0],rep,7) != 7)        {
            fprintf(stderr,"fils : erreur lecture !\n");
            exit(5);
        }

        printf("message du fils : %s\n", rep);
        wait(&status);
    }
    else
    {
        // Tube 1 fermé en écriture
        close(p1[1]);

        // Tube 2 fermé en lecture
        close(p2[0]);

        // Attente message du père
        if(read(p1[0], mesg, 5) != 5)
        {
            fprintf(stderr,"fils : erreur lecture\n");
            exit(6);
        }

        printf("Message reçu par le fils : %s\n", mesg);

        // Envoie message au père
        if(write(p2[1], "Bonjour", 7) != 7)
        {
            fprintf(stderr,"Erreur écriture\n");
            exit(7);
        }

        exit(0);
    }
    return(0);
}
