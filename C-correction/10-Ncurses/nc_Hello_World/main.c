#include <stdio.h>
#include <ncurses.h>

void init_nc(void)
{
    // Start curses mode
	initscr();
}

int the_end(void)
{
    // End curses mode
	endwin();
	return 0;
}

int main(void)
{
    init_nc();

    move(10,20);
    printw("Hello World !!!");	// Print Hello World
    refresh();		        // Print it on to the real screen
    getch();	       		// Wait for user input

    return the_end();
}
