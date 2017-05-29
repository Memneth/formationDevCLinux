#include <stdio.h> //pour la fonction printf()

void gotoxy(int col, int lig){
    printf("\x1b[%d;%df",lig,col);
}
