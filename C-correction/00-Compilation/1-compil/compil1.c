/* 
 * File:   	compil1.c
 * 
 * Compilation: gcc -o compil compil1.c compil2.c
 */

// HEADERS
#include <stdio.h>
#include <stdlib.h>

/* 
 * FONCTION clrscr
 *
 * Effacer l'écran 
 */
void clrscr(void)
{
    printf("\033[2J\033[1;1H");
}

/*
 * FONCTION gotoxy
 * 
 * Placer le curseur sur l'écran
 */
void gotoxy(int col, int lig)
{
    printf("\x1b[%d;%df",lig,col);
}
