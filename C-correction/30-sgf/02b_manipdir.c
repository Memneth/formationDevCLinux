// 02b_manipdir.c

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void clrscr(void)
{
    printf("\033[2J\033[1;1H");
}

int main(void)
{
    char buf[UCHAR_MAX];
    struct dirent *lecture;
    DIR *rep;

    clrs

    rep = opendir("." );

    if (getcwd (buf, UCHAR_MAX) == NULL) {
        return EXIT_FAILURE;
    }

    printf("Répertoire courant %s\n", buf);

    lecture=readdir(rep);

    while (lecture != NULL)    {
    printf("Numéro inode : %d et Nom de fichier %s\n", (int)lecture->d_ino, lecture->d_name);
    lecture=readdir(rep);
    }

    closedir(rep);
    return EXIT_SUCCESS;
}
