 /* 
 * File:   	fic02.c
 * 
* Compilation: gcc -fPIC -c fic01.c fic02.c
 *              gcc -o libfic.so -shared fic01.o fic02.o
 *              
 *              pour voir :
 *              nm -s libfic.so  --defined-only
 */

// HEADERS
#include <stdio.h>

/*
 * FONCTION gotoxy
 * 
 * Placer le curseur sur l'écran
 */
void gotoxy(int col, int lig)
{
    printf("\x1b[%d;%df",lig,col);
}
