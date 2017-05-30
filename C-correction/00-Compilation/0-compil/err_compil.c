 
/* 
 * File:   	err_compil.c
 * 
 * Compilation: gcc -Wall -o compil err_compil.c
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
    print("\033[2J\033[1;1H");
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

/*
 * FONCTION main
 */
int main(void)
{
    clrscr();

    gotoxy(10,15);
    printf("%s\n","Processus de compilation...");

    return (EXIT_SUCCESS);
}
