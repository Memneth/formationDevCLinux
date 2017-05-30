 
/* 
 * File:   	compil.c
 *
 * Compilation:
 * Step 1:      gcc -E compil.c > compil.i
 * Step 2:      gcc -S compil.i
 * Step 3:      gcc -c compil.s
 * 		as -o compil.o compil.s 
 * Step 4:	gcc -o compil compil.o
 * 
 * Or :
 *              gcc -o compil compil.c 
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
