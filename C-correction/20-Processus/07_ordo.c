// 07_ordo.c

#include <stdio.h>
#include <sched.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(void)
{
	pid_t ret, pid;
	int politique, status, priorite;
	struct timespec quantum;
	struct sched_param param;

	ret = fork();

	if (ret == 0)
	{
		pid = getpid();

		printf("je suis le fils :\n");
		printf("Ma priorité d'ordonnancement est %d\n", getpriority(PRIO_PROCESS,pid));
		politique = sched_getscheduler(pid);

		if (politique == SCHED_RR)
			printf("Ma politique d'ordonnancement est SCHED_RR\n");

		if (politique == SCHED_FIFO)
			printf("Ma politique d'ordonnancement est SCHED_FIFO\n");

		if (politique == SCHED_OTHER)
			printf("Ma politique d'ordonnancement est SCHED_OTHER\n");

		param.sched_priority = 10;
		setpriority(PRIO_PROCESS, pid, 10);

		if (sched_setscheduler(pid, SCHED_FIFO, &param) == -1)
			perror("Problème setscheduler");

		priorite = getpriority(PRIO_PROCESS, pid);
		printf("Ma priorité d'ordonnancement est %d\n", priorite);

		politique = sched_getscheduler(pid);

		if (politique == SCHED_RR)
			printf("Ma nouvelle politique d'ordonnancement est SCHED_RR\n");

		if (politique == SCHED_FIFO)
			printf("Ma nouvelle politique d'ordonnancement est SCHED_FIFO\n");

		if (politique == SCHED_OTHER)
			printf("Ma nouvelle politique d'ordonnancement est SCHED_OTHER\n");
	}
	else
	{
		printf("Je suis le père :\n");
		printf("Priorité min %d et max %d de la politique SCHED_FIFO\n", 
			sched_get_priority_min(SCHED_FIFO),
			sched_get_priority_max(SCHED_FIFO));

		printf("Priorité min %d et max %d de la politique SCHED_RR\n", 
			sched_get_priority_min(SCHED_RR),
			sched_get_priority_max(SCHED_RR));
		
		sched_rr_get_interval(0, &quantum);

		printf("Voici les valeurs du quantum de la politique SCHED_RR, %d secondes, %ld nanosecondes\n",
			 (int) quantum.tv_sec,  quantum.tv_nsec);

		wait(&status);
	}
}
