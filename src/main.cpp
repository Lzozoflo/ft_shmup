
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

	(void)av;
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
// 	// Debug::add_debug_nl("y: ", y);
// 	// Debug::add_debug_nl("x: ", x);

    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);

    
    // Taile de la fenetre
    int h, w;
    getmaxyx(stdscr, h, w);

	Debug::add_debug_nl("taille de la windown - h: ", h);
	Debug::add_debug_nl("taille de la windown - w: ", w);
    
    // Création de la fenêtre au centre.
    int starty = (h - (h - 4)) >> 1;
    int startx = (w - (w - 4)) >> 1;
    
    WINDOW *win = newwin(h - 4, w - 4, starty, startx);
    box(win, 0, 0);
    wrefresh(win);

    // Position du "joueur" à l'intérieur de la fenêtre
    int x = (w - 4) >> 1;
    int y = (h - 4) - 2;


    while (is_running) {

        werase(win);                                // Effacer l'intérieur de la fenêtre
        box(win, 0, 0);                             // Ecrie la bordure de la fenêtre

        int ch = getch();

        Debug::add_debug_nl(" Input - ch: ", ch);

        // all input search esc/q(to quit), up, down, right, left,
        if (ch == 'q'|| ch == 27)                   is_running = EXIT;
        else if (ch == KEY_LEFT && x > 1)           x--;
        else if (ch == KEY_RIGHT && x < w - 6)      x++;
        else if (ch == KEY_UP && y > 1)             y--;
        else if (ch == KEY_DOWN && y < h - 6)       y++;

        //a terme ici print board (tab[h-4][w-4])
        mvwprintw(win, y, x, "A");                  // Affiche le joueur dans la fenêtre

        
        wrefresh(win);                              // Rafraîchir la fenêtre
        usleep(FPS30);                              // fps limiter 
    }

    delwin(win);
    endwin();
	delete ptr;
    return 0;
}
