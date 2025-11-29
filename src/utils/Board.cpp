
#include <vector>
#include <ncurses.h>

#include "Debug.hpp"
#include "AGameEntity.hpp"
#include "Empty.hpp"
#include "ShipAlly.hpp"
#include "struct.hpp"

void fill_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {

    Board.clear();
    Board.resize(game.height);

	// Debug::add_debug_nl("int baseposx = game.width >> 1: ", baseposx);
	// Debug::add_debug_nl("int baseposy = game.height - 2: ", baseposy);

    for (int y = 0; y < game.height; ++y) {
        Board[y].resize(game.width);

        for (int x = 0; x < game.width; ++x) {
            if (game.posPlayerX == x && game.posPlayerY == y)
                Board[y][x] = new ShipAlly(); // alloue un pointeur pour chaque case
            else
                Board[y][x] = NULL;  
        }
    }
}

void print_all_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game, WINDOW *win) {
    game.height--;
    game.width--;
    for (int y = 1; y < game.height; ++y) {

        for (int x = 1; x < game.width; ++x) {
            if (Board[y][x]) {                                               // alloue un pointeur pour chaque case
                mvwprintw(win, y, x, "%c", Board[y][x]->getType());          // Affiche le joueur dans la fenêtre
            } else {
                mvwprintw(win, y, x, " ");
            }
        }
    }
    game.height++;
    game.width++;
}

void delete_all_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {

    for (int y = 0; y < game.height; ++y) {

        for (int x = 0; x < game.width; ++x) {
            if (Board[y][x])
                delete Board[y][x];  // alloue un pointeur pour chaque case
        }
    }
}

// void    iter_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {
//     std::vector<std::vector<AGameEntity *> > &Board
// }