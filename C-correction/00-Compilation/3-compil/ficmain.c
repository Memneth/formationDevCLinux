 
/* 
 * File:   	ficmain.c
 * 
 * Compilation: gcc  -L./lib ficmain.c  -o ficmain -lfic
 */

// HEADERS
#include <stdio.h>
#include <stdlib.h>

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
