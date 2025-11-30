
#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <vector>

#include "Debug.hpp"
#include "AGameEntity.hpp"
#include "ShipAlly.hpp"
#include "struct.hpp"
#include "Clock.hpp"



void null_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game );
void fill_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game );
void print_all_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game, WINDOW *win);
void delete_all_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game );
void iter_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game );
void printHpBar(WINDOW *win, int y, int x, int hp, int maxHp, int width);

int main(int ac, char **av) {

	Debug *ptr = NULL;
	if (ac > 2) {
		std::cout << "Error: no agrument needed." << std::endl;
		return (1);
	}
	if (ac == 2) {
		ptr = new Debug(av[1]);
	}
	int is_running = RUN;


	initscr();
	cbreak();
	noecho();
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);

	// Taile de la fenetre
	t_game game;
	getmaxyx(stdscr, game.height, game.width);

	if (game.height < 13 || game.width < 50) {
        endwin();
        std::cerr << "Error: window size too small. Min size 40x15." << std::endl;
        if (ptr != NULL)
            delete ptr;
        return (1);
    }
	game.height -= 7;
	game.width -= 6;
	game.maxEnnemie = game.width / TAUXSPAWN;
	game.nbEnnemie = 0;
	game.shot = false;
	game.gamelife = GAMELIFE;
	// std::string str;
	// str[game.gamelife + 1 ] = ' ';

	// Debug::add_debug_nl("taille de la windown - height: ", height);
	// Debug::add_debug_nl("taille de la windown - width: ", width);

	// Création de la fenêtre au centre.





	WINDOW *win = newwin(game.height, game.width, 5, 3);
	WINDOW *status = newwin(5, game.width, 0, 3);
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_RED);
	wbkgd(win, COLOR_PAIR(1));

	// Position du "joueur" à l'intérieur de la fenêtre
	game.posPlayerX = game.width >> 1;
	game.posPlayerY = game.height - 2;

	std::vector<std::vector<AGameEntity *> > Board; // Board de jeu

	fill_board(Board, game);     // init du Board + Pos de base du joueur
	game.newBoard = Board;
	null_board(game.newBoard, game);
	Clock clock;
	// Debug::add_debug_nl("game.newBoard.size(): ", game.newBoard[1].size());
	// Debug::add_debug_nl("Board.size(): ", Board[1].size());


	while (is_running) {
		int h, w;
		getmaxyx(stdscr, h, w);
		if (h - 7 != game.height || w - 6 != game.width){
			is_running = 21;
			break;
		}
		Debug::add_debug_nl("h: ", h);
		Debug::add_debug_nl("w: ", w);

		werase(win);                                // Effacer l'intérieur de la fenêtre
		box(status, 0, 0);                         // Ecrie la bordure de la fenêtre
		// box(win, 0, 0);                             // Ecrie la bordure de la fenêtre
		mvwprintw(status,1 ,3, "player HP : %d ", Board[game.posPlayerY][game.posPlayerX]->getHp()); 	// Affiche le texte dans la fenêtre principale
		/*int maxBarWidth = game.width - 15; // espace pour écrire "Game HP : "
		int barWidth = (game.gamelife * maxBarWidth) / GAMELIFE;
		std::string bar(barWidth, '=');
		mvwprintw(status, 2, 3, "Game HP : %s", bar.c_str());*/
		printHpBar(status, 2, 3, game.gamelife, GAMELIFE, game.width - 15);
		mvwprintw(status,3 ,3, "Time : %d,%d ", clock.getMinutesSinceStart(), clock.getTimeSinceStart() % 60); 	// Affiche le texte dans la fenêtre principale
		int ch = getch();

		if (ch != -1)
			Debug::add_debug_nl(" Input - ch: ", ch);

		// all input search esc/q(to quit), up, down, right, left,
		if (ch == 'q'|| ch == 27)                                       is_running = EXIT;
		else if (ch == KEY_LEFT && game.posPlayerX > 1)                 game.posPlayerX--;
		else if (ch == KEY_RIGHT && game.posPlayerX < game.width - 2)   game.posPlayerX++;
		else if (ch == KEY_UP && game.posPlayerY > 1)                   game.posPlayerY--;
		else if (ch == KEY_DOWN && game.posPlayerY < game.height - 2)   game.posPlayerY++;
		else if (ch == ' ')                                             game.shot = true;

		try
		{
			iter_board(Board, game);
			if (game.gamelife < 0)
				throw (-21);
		}
		catch(const int &i)
		{
			if (i == -42) {
				mvwprintw(status,1 ,3, "player HP : 0 ");
				mvwprintw(win, (game.height >> 1), (game.width >> 1), "Game over!");
			}
			if (i == -21) {
				if (Board[game.posPlayerY][game.posPlayerX])
					mvwprintw(status,1 ,3, "player HP : %d ", Board[game.posPlayerY][game.posPlayerX]->getHp());
				mvwprintw(win, (game.height >> 1), (game.width >> 1), "Game over!");
			}
			wrefresh(win);
			wrefresh(status);
			usleep(GAMEOVER);
			break;
		}

		print_all_board(Board, game, win);


		clock.fpsLimit(FPS60);						// fps limiter
		wrefresh(win);                              // Rafraîchir la fenêtre
		wrefresh(status);                           // Rafraîchir la fenêtre
		//usleep(FPS60);                            // fps limiter
	}

	delete_all_board(game.newBoard, game);
	delete_all_board(Board, game);
	delwin(win);
	delwin(status);
	endwin();
	if (ptr != NULL)
	delete ptr;
	if (is_running == 21){
		std::cerr << "\nDo not change the size.\n";
	}
	return 0;
}
