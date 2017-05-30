 /* 
 * File:   	fic01.c
 * 
 * Compilation: mkdir ./lib
 *              gcc -fPIC -shared -Wl,-soname,libfic.so.1 -o lib/libfic.so.1.0 fic01.c fic02.c
 *
 *              cd lib
 *              ln -sf libfic.so.1.0 libfic.so 
 *
 *              Dans /etc/ld.so.conf.d créez 1 fichier mylibs.conf
 *              Ajouter le chemin du répertoire lib
 *              ldconfig 
 *
 *              Vérifiez :  ldconfig -v |grep libfic
 */

// HEADERS
#include <stdio.h>

/* 
 * FONCTION clrscr
 *
 * Effacer l'écran 
 */
void clrscr(void)
{
    printf("\033[2J\033[1;1H");
}
