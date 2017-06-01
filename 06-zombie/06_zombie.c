/*
 * 06_zombie.c
 *
 * fonction main
 * sans arg et avec code retour
 * appel de la fonction fork()
 *
 *le père dort
 *le fils sort immediatement
 *
 *
 * gcc -o zombie 06_zombie.c
 *
 *lancer l'exec en sous tache
 * ./zombie&
 *
 * visualiser le zombie cde top
 * ps xaf
 *
 * killer le processus zombie
 * La seule manière d’éliminer ces processus zombies consiste
 * à causer la mort du processus parent, par exemple au moyen du signal SIGKILL
 * xkill
 */


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid;
    child_pid = fork();
    if(child_pid>0){
        printf("Nous sommmes dans le processus parent attendre 1 mn..\n");
        sleep(60);
        }else{
            printf("Nous sommmes dans le processus fils,sortie immédiate\n");
            exit;
            }
    return 0;
}

