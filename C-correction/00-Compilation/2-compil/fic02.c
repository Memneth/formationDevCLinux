 
/* 
 * File:   	fic02.c
 * 
 * Compilation: gcc -c fic02.c
 *              
 *              mkdir ./libs
 *              ar rcs libs/libfic.a fic01.o fic02.o 
 * 
 *              Pour voir :
 *              ar t libfic.a
 *              nm -s libs/libfic.a
 *              nm -s --defined-only libs/libfic.a
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
