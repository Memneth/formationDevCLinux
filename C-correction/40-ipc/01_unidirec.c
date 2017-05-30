// communication unidirectionnelle (tube anonyme) entre un père et un fils
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {
    int p[2], status;
    pid_t ret;
    char chaine[7];

    pipe(p);
    ret=fork();

    if(ret == 0)     {
        // Fils écrit dans le tube
        // Pas lecture dans le tube
        close(p[0]);

        write(p[1],"Bonjour",7);
        close(p[1]);
        exit(0);
    }
    else     {
        // Père lit le tube
        // Pas écriture dans le tube
        close(p[1]);

        read(p[0],chaine,7);
        close(p[0]);
        printf("%s\n", chaine);
        wait(&status);
    }
    return(0);
}

