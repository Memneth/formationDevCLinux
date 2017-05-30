 
/* 
 * File:   	fic01.c
 * 
 * Compilation: gcc -c fic01.c
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
 * FONCTION clrscr
 *
 * Effacer l'écran 
 */
void clrscr(void)
{
    printf("\033[2J\033[1;1H");
}

