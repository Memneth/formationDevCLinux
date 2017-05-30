// 02a_manipdir.c

#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void clrscr(void)
{
    printf("\033[2J\033[1;1H");
}

int main(void)
{
    char nom[20];
    struct dirent *lecture;
    DIR *rep;
    
    clrscr();
    
    rep = opendir("." );
    
    while ((lecture = readdir(rep)))
    {
	printf("%s\n", lecture->d_name);
    }

    closedir(rep);
}
