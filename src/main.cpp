
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <vector>

#include "Debug.hpp"
#include "AGameEntity.hpp"
#include "Empty.hpp"
#include "ShipAlly.hpp"
#include "struct.hpp"

#define FPS30   32000// limit 60 fps 
#define FPS60   16000// limit 60 fps 
#define FPS120   8000// limit 120 fps 
#define RUN	    1
#define EXIT	0


void fill_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game );
void print_all_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game, WINDOW *win);
void delete_all_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game );

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
    t_game game;
    getmaxyx(stdscr, game.height, game.width);

    game.height -= 4;
    game.width -= 4;
	
    // Debug::add_debug_nl("taille de la windown - height: ", height);
	// Debug::add_debug_nl("taille de la windown - width: ", width);
    
    // Création de la fenêtre au centre.
    
    WINDOW *win = newwin(game.height, game.width, 2, 2);

    // Position du "joueur" à l'intérieur de la fenêtre
    game.posPlayerX = game.width >> 1;
    game.posPlayerY = game.height - 2;

    std::vector<std::vector<AGameEntity *> > Board; // Board de jeu
    fill_board(Board, game);     // init du Board + Pos de base du joueur

    while (is_running) {

        werase(win);                                // Effacer l'intérieur de la fenêtre
        box(win, 0, 0);                             // Ecrie la bordure de la fenêtre

        int ch = getch();

        if (ch != -1)
            Debug::add_debug_nl(" Input - ch: ", ch);

        // all input search esc/q(to quit), up, down, right, left,
        if (ch == 'q'|| ch == 27)                                       is_running = EXIT;
        else if (ch == KEY_LEFT && game.posPlayerX > 1)                 game.posPlayerX--;
        else if (ch == KEY_RIGHT && game.posPlayerX < game.width - 2)   game.posPlayerX++;
        else if (ch == KEY_UP && game.posPlayerY > 1)                   game.posPlayerY--;
        else if (ch == KEY_DOWN && game.posPlayerY < game.height - 2)   game.posPlayerY++;
        else if (ch == ' ')                                             Debug::add_debug_nl("piou paw");


        print_all_board(Board, game, win);

        // mvwprintw(win, y, x, "A");                  // Affiche le joueur dans la fenêtre


        wrefresh(win);                              // Rafraîchir la fenêtre
        usleep(FPS30);                              // fps limiter 
    }

    delete_all_board(Board, game);
    delwin(win);
    endwin();
    if (ptr != NULL)
    	delete ptr;
    return 0;
}
//384