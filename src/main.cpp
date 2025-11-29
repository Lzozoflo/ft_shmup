

#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <vector>

#include "Debug.hpp"
#include "AGameEntity.hpp"
#include "Empty.hpp"

#define FPS30   32000// limit 60 fps 
#define FPS60   16000// limit 60 fps 
#define FPS120   8000// limit 120 fps 
#define RUN	    1
#define EXIT	0


void fill_board( std::vector<std::vector<AGameEntity *> > &Board, int height, int width ) {

    Board.clear();
    Board.resize(height);

    for (int y = 0; y < height; ++y) {
        Board[y].resize(width);

        for (int x = 0; x < width; ++x) {
            Board[y][x] = new Empty();  // alloue un pointeur pour chaque case
        }
    }
}

void print_all_board( std::vector<std::vector<AGameEntity *> > &Board, int height, int width, WINDOW *win) {
    std::string s;

    for (int y = 1; y < height; ++y) {

        for (int x = 1; x < width; ++x) {
            s = Board[y][x]->getType();                                // alloue un pointeur pour chaque case
            mvwprintw(win, y, x, "%s",s.c_str());                           // Affiche le joueur dans la fenêtre
        }
    }
}

void delete_all_board( std::vector<std::vector<AGameEntity *> > &Board, int height, int width ) {

    for (int y = 0; y < height; ++y) {

        for (int x = 0; x < width; ++x) {
            delete Board[y][x];  // alloue un pointeur pour chaque case
        }
    }
}

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


    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    nodelay(stdscr, TRUE);
    
    // Taile de la fenetre
    int height, width;
    getmaxyx(stdscr, height, width);

	// Debug::add_debug_nl("taille de la windown - height: ", height);
	// Debug::add_debug_nl("taille de la windown - width: ", width);
    
    // Création de la fenêtre au centre.
    int starty = (height - (height - 4)) >> 1;      // 2 ??
    int startx = (width - (width - 4)) >> 1;        // 2 ??
    
    WINDOW *win = newwin(height - 4, width - 4, starty, startx);

    // Position du "joueur" à l'intérieur de la fenêtre
    int x = (width - 4) >> 1;
    int y = (height - 4) - 2;
    std::vector<std::vector<AGameEntity *> > Board;

    fill_board(Board, (height - 4), (width - 4));

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



        print_all_board(Board, (height - 5), (width - 5), win);
        //a terme ici print board (tab[height - 4][width - 4])
        mvwprintw(stdscr, 1, 1, "%d", x);                  // Affiche le joueur dans la fenêtre

        




        wrefresh(win);                              // Rafraîchir la fenêtre
        usleep(FPS30);                              // fps limiter 
    }


    delete_all_board(Board, (height - 4), (width - 4));
    delwin(win);
    endwin();
    if (ptr != NULL)
    	delete ptr;
    return 0;
}
//384