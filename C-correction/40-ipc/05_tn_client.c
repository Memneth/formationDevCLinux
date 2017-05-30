// 05_tn_client.c

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    int tub1, tub2;
    int nb1, nb2, res;
    char ent1[2], ent2[2], ent3[2];
    char fd1[10], fd2[10];

    //ouverture tube 1 en écriture
    tub1=open("tube1", O_WRONLY);

    //ouverture tube 2 en lecture
    tub2=open("tube2", O_RDONLY);

    printf("Saisir 2 nombres à additionner : ");
    scanf("%d %d", &nb1, &nb2);

    //écriture dans tube 1
    sprintf(ent1, "%d", nb1);
    write(tub1, ent1, 2);
    sprintf(ent2, "%d", nb2);
    write(tub1, ent2, 2);

    //lecture depuis tube 2
    read(tub2, ent3, 2);
    res=atoi(ent3);
    printf("Résultat reçu : %d\n", res);

    //Fermeture des tubes
    close(tub1);
    close(tub2);

    //Destruction des tubes
    sprintf(fd1, "%d", tub1);
    unlink(fd1);
    sprintf(fd2, "%d", tub2);
    unlink(fd2);

    return(0);
}

