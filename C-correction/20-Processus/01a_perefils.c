// 01a_perefils.c
// gcc 01a_perefils.c -o 01a_perefils

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Fonction main
int main(void)
{
        pid_t pid = fork();

        if(pid == 0)
        {
		printf("Je suis le fils, mon pid est %d. Mon ppid est %d\n", getpid(), getppid());
        }
        else
        {
		printf("Je suis le père, mon pid est %d. Le pid de mon fils est %d\n", getpid(), pid);
        }
	
	return 0;
}

