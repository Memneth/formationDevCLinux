// 01_sigint.c

#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
	char chaine[10];
	int i;
	sigset_t ens,ens1;

	sigemptyset(&ens);
	sigaddset(&ens, SIGINT);
	sigprocmask(SIG_SETMASK, &ens, 0);

	printf("Traitement en cours...\n");

	i=0;
	while(i < 1000000000)
	{
		i++;
	}

	sigpending(&ens1);

	if(sigismember(&ens1, SIGINT))
		printf("SIGINT appuyé\n");

	sigemptyset(&ens);
	sigprocmask(SIG_SETMASK, &ens, 0);
	printf("Signaux débloqués\n");
}
