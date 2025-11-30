#include "struct.hpp"
#include "Debug.hpp"

#include <cstdlib>
#include <ncurses.h>
#include <vector>

void fill_background( std::vector<std::vector<t_type_Background> > &Board, t_game &game ) {

	Board.clear();
	Board.resize(game.height);

	// Debug::add_debug_nl("game.posPlayerX: ", game.posPlayerX);
	// Debug::add_debug_nl("game.posPlayerY: ", game.posPlayerY);

	for (int y = 0; y < game.height; ++y) {
		Board[y].resize(game.width);

	}
}

void random_background( std::vector<std::vector<t_type_Background> > &Board, t_game &game ) {

	// Debug::add_debug_nl("game.posPlayerX: ", game.posPlayerX);
	// Debug::add_debug_nl("game.posPlayerY: ", game.posPlayerY);

	for (int x = 0; x < game.width; ++x) {
		switch (rand() % 1000) {
			case 0:
			case 1:
				Board[1][x] = STAR1;
				break;
			case 2:
				Board[1][x] = STAR2;
				break;
			case 3:
				Board[1][x] = STAR3;
				break;
			default:
				Board[1][x] = EMPTY0;
				break;
		}
	}
}

void move_background( std::vector<std::vector<t_type_Background> > &Board, t_game &game ) {

	// Debug::add_debug_nl("game.posPlayerX: ", game.posPlayerX);
	// Debug::add_debug_nl("game.posPlayerY: ", game.posPlayerY);
	for (int y = game.height - 2; y >= 0; --y){
		for (int x = 0; x < game.width; ++x) {
			if (Board[y][x] != EMPTY0) {
				Board[y + 1][x] = STAR1;
				Board[y][x] = EMPTY0;
			}
		}
	}
}

void print_background( std::vector<std::vector<t_type_Background> > &Board, t_game &game, WINDOW *win) {

	// Debug::add_debug_nl("game.posPlayerX: ", game.posPlayerX);
	// Debug::add_debug_nl("game.posPlayerY: ", game.posPlayerY);
	t_type_Background bg;
	for(int y = 0; y < game.height - 1; ++y) {
		for (int x = 0; x < game.width; ++x) {
			bg = Board[y][x];
			if (bg == EMPTY0) {
				mvwprintw(win, y, x, "");
			} else if (bg == STAR1) {
				mvwprintw(win, y, x, ".");
			} else if (bg == STAR2) {
				mvwprintw(win, y, x, "'");
			} else if (bg == STAR3) {
				mvwprintw(win, y, x, "`");
			}
		}
	}
}