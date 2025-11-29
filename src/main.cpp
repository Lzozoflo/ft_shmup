

#include <iostream>
#include <unistd.h>
#include <ncurses.h>

#include "Windown.hpp"
#include "Debug.hpp"

#define FPS30   32000// limit 60 fps 
#define FPS60   16000// limit 60 fps 
#define FPS120   8000// limit 120 fps 
#define RUN	    1
#define EXIT	0


int main(int ac, char **av) {

	Debug *ptr = NULL;
	if (ac > 2) {
		std::cout << "Error: no agrument needed." << std::endl;
		return (1);
	}
	if (ac == 2) {
		ptr = new Debug(av[1]);
	}
    bool is_running = RUN;

// 	// Debug::add_debug_nl("Voila comment ecrire une ligne de debug !");

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    
    // Taile de la fenetre
    int height, width;
    getmaxyx(stdscr, height, width);

	Debug::add_debug_nl("taille de la windown - height: ", height);
	Debug::add_debug_nl("taille de la windown - width: ", width);
    
    // Création de la fenêtre au centre.
    int starty = (height - (height - 4)) >> 1;      // 2 ??
    int startx = (width - (width - 4)) >> 1;        // 2 ??
    
    WINDOW *win = newwin(height - 4, width - 4, starty, startx);

    // Position du "joueur" à l'intérieur de la fenêtre
    int x = (width - 4) >> 1;
    int y = (height - 4) - 2;


    while (is_running) {

        werase(win);                                // Effacer l'intérieur de la fenêtre
        box(win, 0, 0);                             // Ecrie la bordure de la fenêtre

        int ch = getch();

        if (ch != -1)
            Debug::add_debug_nl(" Input - ch: ", ch);

        // all input search esc/q(to quit), up, down, right, left,
        if (ch == 'q'|| ch == 27)                   is_running = EXIT;
        else if (ch == KEY_LEFT && x > 1)           x--;
        else if (ch == KEY_RIGHT && x < width - 6)  x++;
        else if (ch == KEY_UP && y > 1)             y--;
        else if (ch == KEY_DOWN && y < height - 6)  y++;




        //a terme ici print board (tab[height - 4][width - 4])
        mvwprintw(win, y, x, "A");                  // Affiche le joueur dans la fenêtre

        




        wrefresh(win);                              // Rafraîchir la fenêtre
        usleep(FPS30);                              // fps limiter 
    }
    // std::vector<>

    delwin(win);
    endwin();
    if (ptr != NULL)
    	delete ptr;
    return 0;
}
