// 01b_perefils.c
// gcc 01b_perefils.c -o 01b_perefils

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

// Fonction main
int main(void)
{
	pid_t pid = fork();
	int status;

	if(pid ==0)
	{
		printf("Je suis le fils, mon pid est %d. Mon ppid est %d\n", getpid(), getppid());
	}
	else if(pid != -1)
	{
		printf("Je suis le père, mon pid est %d. Le pid de mon fils est %d\n", getpid(), pid);
	}
	else
	{
		perror("erreur");
		return 1;
	}
	waitpid(-1, &status, 0);
	return 0;
}
