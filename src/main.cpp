
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

    // int is_running = 1;
    initscr();            // Initialise ncurses
    cbreak();          
    noecho();             // Désactive l'affichage des input
	int y = (LINES - HEIGHT);
	int x = (COLS - WIDTH);
	// Debug::add_debug_nl("Voila comment ecrire une ligne de debug !");
	// Debug::add_debug_nl("y: ", y);
	// Debug::add_debug_nl("x: ", x);
	

	WINDOW *win = newwin(HEIGHT, WIDTH, y, x);
	box(win, 0, 0);
	refresh();

    mvwprintw(win, 1, 1, "Hello World !");
	wrefresh(win);



    // curs_set(0);
    // keypad(stdscr, TRUE);
    // nodelay(stdscr, TRUE);

    // if (has_colors()) {
    //     start_color();
    //     init_pair(1, COLOR_GREEN, COLOR_BLACK);
    // }


    // while (is_running) {
    //     int ch = getch();
    //     if (ch == 'q' || ch == 27)
    //         is_running = 0;
		

    //     if (ch == KEY_LEFT) x--;
    //     if (ch == KEY_RIGHT) x++;

    //     clear();
    //     mvwprintw(win, 1, x, "A"); // Joueur

    //     refresh();
	// 	wrefresh(win);

    	// usleep(16000);      // Limite à ~60 FPS
        usleep(2000000);
    // }

    endwin();


	delete ptr;
	return (0);
}
