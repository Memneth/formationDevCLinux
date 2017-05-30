// 04_tn_uni2.c

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
        char zone[10];
        int tub;

        //ouverture tube
        tub=open("fictub",O_RDONLY);

        //lecture dans tube
        read(tub, zone, 10);
        zone[10]=0;
        printf("Processus lecteur du tube nommé fictub : %s\n", zone);

        //fermeture tube
        close(tub);

        return(0);
}

