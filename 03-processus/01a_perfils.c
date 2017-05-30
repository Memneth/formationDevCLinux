/*
 * 01a_perfils.c
 *
 * Copyright 2017 bob <bob@dev>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 *
 *
 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(void)
{
    // création d'un fork
    pid_t fils;
    fils = fork();

    int status;

    if (fils==0)
    {
       printf("je suis le fils, mon pid est %d , le pid de mon père est %d\n",getpid(),getppid());
    }
    else
    {
       printf("je suis le pere, mon pid est %d , le pid de mon fils est %d\n",getpid(),fils);
    }
    //période d'attente
     wait(&status);
    return 0;
}
