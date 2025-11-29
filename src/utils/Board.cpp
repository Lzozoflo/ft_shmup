
#include <vector>
#include <ncurses.h>

#include "Debug.hpp"
#include "AGameEntity.hpp"
#include "ShipAlly.hpp"
#include "ShipEnnemie.hpp"
#include "struct.hpp"


void fill_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {

    Board.clear();
    Board.resize(game.height);

	// Debug::add_debug_nl("game.posPlayerX: ", game.posPlayerX);
	// Debug::add_debug_nl("game.posPlayerY: ", game.posPlayerY);

    for (int y = 0; y < game.height; ++y) {
        Board[y].resize(game.width);
        for (int x = 0; x < game.width; ++x) {
            if (game.posPlayerX == x && game.posPlayerY == y){
                Board[y][x] = new ShipAlly();
            }  else {
                Board[y][x] = NULL;  
            }
            // if (y == 1 && !Board[y][x]) {
            //     Board[y][x] = new ShipEnnemie();
            // }
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
    static int posPlayerY = game.posPlayerY;
    static int posPlayerX = game.posPlayerX;


    switch (Board[y][x]->getType())
    {
        case BULLETALLY:{
            // up
            if ((y - 1) > 1 && !Board[y - 1][x])
                Debug::add_debug_nl("bullet up");
            break;
        }
        case BULLETENNEMIE:{
            // down
            if ((y + 1) < (game.height - 2) && Board[y + 1][x])
                Debug::add_debug_nl("bullet down");
            break;
        }
        case SHIPALLY:{
                // game.posPlayerY = posPlayerY;
                // game.posPlayerX = posPlayerX;
                // break;

            if (Board[y][x]->getHp() < 1)
                throw(-42);  // dead so dont copy
            if (!Board[game.posPlayerY][game.posPlayerX] && (posPlayerY != game.posPlayerY || posPlayerX != game.posPlayerX)){
                posPlayerY = game.posPlayerY;
                posPlayerX = game.posPlayerX;

                ShipAlly *ptr = dynamic_cast<ShipAlly *>(Board[y][x]);
                if (ptr == NULL)
                    Debug::add_debug_nl("aled y pb la");
                game.newBoard[posPlayerY][posPlayerX] = ptr->clone();
            } else if (y == game.posPlayerY && x == game.posPlayerX){
                ShipAlly *ptr = dynamic_cast<ShipAlly *>(Board[y][x]);
                if (ptr == NULL)
                    Debug::add_debug_nl("aled y pb la");
                game.newBoard[y][x] = ptr->clone();
            } else if (Board[game.posPlayerY][game.posPlayerX]) {
                ShipAlly *ptr = dynamic_cast<ShipAlly *>(Board[y][x]);
                if (ptr == NULL)
                    Debug::add_debug_nl("aled y pb la");
                game.newBoard[game.posPlayerY][game.posPlayerX] = ptr->clone();
                Board[game.posPlayerY][game.posPlayerX] = ptr->clone();
            }
            // Board[y][x]->takeDamage(1);
            break;
        }
        case SHIPENNEMIE:{
            if (Board[y][x]->getHp() < 1){
                game.nbEnnemie--;
                break;
            }
                
            ShipEnnemie *ptr = dynamic_cast<ShipEnnemie *>(Board[y][x]);
            if (ptr == NULL)
                Debug::add_debug_nl("aled y pb la");
            game.newBoard[y][x] = ptr->clone();
            // ia rand for move and hit
            break;
        }
        default:
            break;
    }
}

#include <cstdlib>

void    iter_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {
    static int iter = 20;
    int random = std::rand() % game.width;

    for (int y = 0; y < game.height; ++y) {
        for (int x = 0; x < game.width; ++x) {
            if (Board[y][x]){
               all_case(Board, game, y, x);
            }
            if (y == 1 && !Board[y][x] && random == x && iter-- == 0) {
                if (game.nbEnnemie == game.maxEnnemie)
                    continue;
                iter = 20;
                game.nbEnnemie++;
                game.newBoard[y][x] = new ShipEnnemie();
            }
        }
    }

    delete_all_board(Board, game);
    null_board(Board, game);
    copie_board(Board, game.newBoard, game);
    null_board(game.newBoard, game);
}
