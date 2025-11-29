
#include <iostream>
#include <unistd.h>
#include <ncurses.h>

#include "Windown.hpp"
#include "Debug.hpp"

#define HEIGHT	10
#define WIDTH	40



int main(int ac, char **av)
{
	(void)av;
	Debug *ptr = NULL;
	if (ac > 2) {
		std::cout << "Error: no agrument needed." << std::endl;
		return (1);
	}
	if (ac == 2) {
		ptr = new Debug(av[1]);
	}

	Debug::add_debug(LINES);


    // initscr();            // Initialise ncurses
    // cbreak();          
    // noecho();             // Désactive l'affichage des input

	// int y = (LINES - HEIGHT) >> 1;
	// int x = (COLS - WIDTH) >> 1;



	// WINDOW *win = newwin(HEIGHT, WIDTH, y, x);
	// box(win, 0, 0);
	// refresh();

    // mvwprintw(win, 1, 1, "Hello World !");
	// wrefresh(win);

	// getch();				// Wait input

    // endwin();				// Quitte proprement



    // int maxx, maxy; // Maximum x and y values of the screen
    // getmaxyx(stdscr, maxy, maxx);



    // curs_set(0);          // Cache le curseur
    // nodelay(stdscr, TRUE); // getch non bloquant
	
    // if (has_colors()) {
    //     start_color();
    //     init_pair(1, COLOR_GREEN, COLOR_BLACK);
    // }

    // attron(COLOR_PAIR(1));
    // mvprintw(5, 10, "Initialisation reussie !");
    // attroff(COLOR_PAIR(1));

    // refresh();            // Affiche le rendu
    // sleep(2);

	delete ptr;
	return (0);
}
