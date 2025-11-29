
#include <vector>
#include <ncurses.h>

#include "Debug.hpp"
#include "AGameEntity.hpp"
#include "Empty.hpp"
#include "ShipAlly.hpp"

void fill_board( std::vector<std::vector<AGameEntity *> > &Board, int height, int width ) {

    Board.clear();
    Board.resize(height);

    // Position du "joueur" à l'intérieur de la fenêtre
    int baseposx = width >> 1;
    int baseposy = height - 2;

	// Debug::add_debug_nl("int baseposx = width >> 1: ", baseposx);
	// Debug::add_debug_nl("int baseposy = height - 2: ", baseposy);

    for (int y = 0; y < height; ++y) {
        Board[y].resize(width);

        for (int x = 0; x < width; ++x) {
            if (baseposx == x && baseposy == y)
                Board[y][x] = new ShipAlly(); // alloue un pointeur pour chaque case
            else
                Board[y][x] = NULL;  
        }
    }
}

void print_all_board( std::vector<std::vector<AGameEntity *> > &Board, int height, int width, WINDOW *win) {
    std::string s;

    height--;
    width--;
    for (int y = 1; y < height; ++y) {

        for (int x = 1; x < width; ++x) {
            if (Board[y][x]) {
                s = Board[y][x]->getType();                                // alloue un pointeur pour chaque case
                mvwprintw(win, y, x, "%s",s.c_str());                           // Affiche le joueur dans la fenêtre
            } else {
                mvwprintw(win, y, x, " ");
            }
        }
    }
}

void delete_all_board( std::vector<std::vector<AGameEntity *> > &Board, int height, int width ) {

    for (int y = 0; y < height; ++y) {

        for (int x = 0; x < width; ++x) {
            if (Board[y][x])
                delete Board[y][x];  // alloue un pointeur pour chaque case
        }
    }
}
