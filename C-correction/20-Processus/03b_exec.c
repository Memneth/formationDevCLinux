//03b_exec.c

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

void main(void)
{
    pid_t pid;
    int i,j;
    char conv1[10], conv2[10];
    
    printf("Donnez la valeur de i : ");
    scanf("%d",&i);
    printf("Donnez la valeur de j : ");
    scanf("%d",&j);

    pid=fork();
        
    if(pid == 0)
    {
        sprintf(conv1, "%d", i);
        sprintf(conv2, "%d", j);
        
        execl("./calculer", "Calcul", conv1, conv2, NULL);
    }
    else
    {
        wait();
    }
}

