// 03_tn_uni.c

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(void)
{
    mode_t mode;
    int tub;

    mode= S_IRUSR | S_IWUSR;

    //création tube nommé
    mkfifo("fictub",mode);

    //ouverture tube
    tub=open("fictub",O_WRONLY);

    //écriture dans tube
    write(tub, "0123456789", 10);

    //fermeture tube
    close(tub);

    return(0);
}
