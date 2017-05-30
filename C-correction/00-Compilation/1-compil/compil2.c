 
/* 
 * File:   	compil2.c
 * 
 * Compilation: gcc -o compil compil1.c compil2.c
 */

// HEADERS
#include <stdio.h>
#include <stdlib.h>
#include "compil1.h"

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
