// 05b_proc.c
// Héritage de variables entre processus lourds
// Compilation : gcc 05b_proc.c -o 05b_proc -lpthread

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int i;

void somme(void)
{
    i += 10;
    printf("Fils %d\n",i);
    i += 20;
    printf("Fils %d\n",i);
}

int main(void)
{
    int pid;
    i=0;
    
    pid=fork();
    
    if(pid == 0)
      {
	somme();
      }
    else
    {
	i=i+1000;
	printf("Père : %d\n", i);
	i=i+2000;
	printf("Père : %d\n", i);
	wait(0);
    }
    
    return 0;
}
