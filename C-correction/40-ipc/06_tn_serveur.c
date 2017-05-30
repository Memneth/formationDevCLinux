// 06_tn_serveur.c

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

    mode_t mode;
    mode = S_IRUSR | S_IWUSR;

    //création de 2 tubes
    mkfifo("tube1", mode);
    mkfifo("tube2", mode);

    //ouverture tube 1 en lecture
    tub1=open("tube1", O_RDONLY);

    //ouverture tube 2 en écriture
    tub2=open("tube2", O_WRONLY);

    //lecture dans tube 1
    read(tub1, ent1, 2);
    nb1=atoi(ent1);
    read(tub1, ent2, 2);
    nb2=atoi(ent2);

    //traitement
    res = nb1 + nb2;
    sprintf(ent3,"%d",res);

    //écriture dans tube 2
    write(tub2, ent3, 2);

    //Fermeture des tubes
    close(tub1);
    close(tub2);

    return(0);
}

