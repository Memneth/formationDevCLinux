// 03a_exec.c

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Fonction main
void main(void)
{
	pid_t pid = fork();

	if(pid == -1)
	{
		printf("Erreur création de processus");
	}
	else if(pid == 0)
	{
		printf("je suis le fils, mon PID est %d, mon PPID (PID de mon père) est %d\n", getpid(), getppid());
		execlp("ls","ls","-l","/",NULL);
	}
	else
	{
		printf("Je suis le père, mon PID est %d\n", getpid());
		printf("Le PID de mon fils est %d\n", pid);
		wait();
	}
}
