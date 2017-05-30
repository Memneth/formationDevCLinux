// 02_termfils.c

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


// Fonction main
int main(void)
{
	pid_t pid, fils_mort;
	int status;

	pid = fork();

	if(pid == 0)
	{
		printf("je suis le fils, mon PID est %d\n", getpid());
		printf("PID de mon père, %d\n",getppid()); 
	}
	else 
	{
		printf("je suis le père, mon PID est %d\n", getpid());
		printf("PID de mon fils, %d\n", pid);
		fils_mort = wait(&status);
		printf("Je suis le père. Le PID de mon fils mort est %d\n", fils_mort);

		if (WIFEXITED(status))
			printf("Je suis le père. Le code retour de mon fils est %d\n", WEXITSTATUS(status));
	}
}
