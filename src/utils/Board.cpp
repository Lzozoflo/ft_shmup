
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

	// Debug::add_debug_nl("game.posPlayerX: ", game.posPlayerX);
	// Debug::add_debug_nl("game.posPlayerY: ", game.posPlayerY);

    for (int y = 0; y < game.height; ++y) {
        Board[y].resize(game.width);
        for (int x = 0; x < game.width; ++x) {
            if (game.posPlayerX == x && game.posPlayerY == y)
                Board[y][x] = new ShipAlly();
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
            if (Board[y][x]) {
                mvwprintw(win, y, x, "%c", Board[y][x]->getType());          // Affiche l'Entity dans la fenetre
            } else {
                mvwprintw(win, y, x, " ");
            }
        }
    }
    game.height++;
    game.width++;
}


void null_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {
    for (int y = 0; y < game.height; ++y) {
        for (int x = 0; x < game.width; ++x) {
            Board[y][x] = NULL;  
        }
    }
}


void    copie_board( std::vector<std::vector<AGameEntity *> > &Board,  std::vector<std::vector<AGameEntity *> > &newBoard, t_game &game ) {
    for (int y = 0; y < game.height; ++y) {
        for (int x = 0; x < game.width; ++x) {
            Board[y][x] = newBoard[y][x];  
        }
    }
    
}


void delete_all_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {
    for (int y = 0; y < game.height; ++y) {
        for (int x = 0; x < game.width; ++x) {
            if (Board[y][x])
                delete Board[y][x];
        }
    }
}


void    all_case( std::vector<std::vector<AGameEntity *> > &Board, t_game &game, int &y, int &x) {
    switch (Board[y][x]->getType())
    {
        case BULLETALLY:
            // up
            break;
        case BULLETENNEMIE:
            // down
            break;
        case SHIPALLY:{
            if (Board[y][x]->getHp() < 1)
                break;
            ShipAlly *ptr = dynamic_cast<ShipAlly *>(Board[y][x]);
            if (ptr == NULL)
                Debug::add_debug_nl("aled y pb la");
            game.newBoard[game.posPlayerY][game.posPlayerX] = ptr->clone();
            break;
        }
        case SHIPENNEMIE:
            // ia rand for move and hit
            break;
        default:
            break;
    }
}

void    iter_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {

    for (int y = 0; y < game.height; ++y) {
        for (int x = 0; x < game.width; ++x) {
            if (Board[y][x]){
                all_case(Board, game, y, x);
            }
        }
    }

    delete_all_board(Board, game);
    null_board(Board, game);
    copie_board(Board, game.newBoard, game);
    null_board(game.newBoard, game);
}
