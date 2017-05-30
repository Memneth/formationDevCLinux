// 06f_zombie.c
// Compilation : gcc 06_zombie.c -o 06_zombie

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  pid_t child_pid;

  child_pid = fork ();

  if (child_pid > 0) {
    printf("Nous sommes dans le processus parent. Attente d'une minute...\n");
    sleep(60);
  }
  else {
    printf("Nous sommes dans le processus fils. Sortie immédiate.\n");
    exit;
  }
  return(0);
}
