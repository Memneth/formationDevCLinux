// 01c_perefils.c

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

// Fonction main
int main(void)
{
	pid_t pid,fils_mort;
	int status;
	pid=fork();

	if(pid ==0)
	{
		printf("Je suis le fils, mon pid est %d. Mon ppid est %d\n", getpid(), getppid());
	}
	else
	{
		printf("Je suis le père, mon pid est %d. Le pid de mon fils est %d\n", getpid(), pid);
		fils_mort = wait(&status);
		printf("Je suis le père et le pid de mon fils mort est %d\n",fils_mort);

		if (WIFEXITED(status))
			printf("Je suis le père et le code retour de mon fils est %d\n",WEXITSTATUS(status));
	}
}
