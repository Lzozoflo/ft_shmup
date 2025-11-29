
#include <vector>
#include <ncurses.h>

#include "Debug.hpp"
#include "AGameEntity.hpp"
#include "ShipAlly.hpp"
#include "ShipEnnemie.hpp"
#include "BulletAlly.hpp"
#include "BulletEnnemie.hpp"
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


void copie_board( std::vector<std::vector<AGameEntity *> > &Board,  std::vector<std::vector<AGameEntity *> > &newBoard, t_game &game ) {
	for (int y = 0; y < game.height; ++y) {
		for (int x = 0; x < game.width; ++x) {
			if (newBoard[y][x] && newBoard[y][x]->getHp() >= 1)
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
		case BULLETALLY:{

			BulletAlly *ptr = dynamic_cast<BulletAlly *>(Board[y][x]);

			Debug::add_debug_nl("BulletAlly");
			game.newBoard[y][x] = ptr->clone();
			break;
		}
		case BULLETENNEMIE:{
			// down
			// BulletEnnemie *ptr = dynamic_cast<BulletEnnemie *>(Board[y][x]);
			if ((y + 1) < (game.height - 2) && Board[y + 1][x])
				Debug::add_debug_nl("bullet down");
			// game.newBoard[y][x] = ptr->clone();
			break;
		}
		case SHIPALLY:{
			AShip *ptr = dynamic_cast<AShip *>(Board[y][x]);
			game.newBoard[y][x] = ptr->clone();
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
#define NBDIFF 20

void    iter_board( std::vector<std::vector<AGameEntity *> > &Board, t_game &game ) {
	static int iter = NBDIFF;
	int random = std::rand() % game.width;

	static int posPlayerY = game.posPlayerY;
	static int posPlayerX = game.posPlayerX;

	if (!(posPlayerY == game.posPlayerY && posPlayerX == game.posPlayerX)) {
		ShipAlly *Shipptr = dynamic_cast<ShipAlly *>(Board[posPlayerY][posPlayerX]);
		if (Board[game.posPlayerY][game.posPlayerX]) {

			t_type_AgameEntity value = Board[game.posPlayerY][game.posPlayerX]->getType();
			if (value == BULLETALLY || value == BULLETENNEMIE) {

				ABullet *bulletptr = dynamic_cast<ABullet *>(Board[game.posPlayerY][game.posPlayerX]);
				int dmg = bulletptr->getDamage();
				Shipptr->takeDamage(dmg);
				Debug::add_debug_nl("Bullet dmg - hp: ", Shipptr->getHp());

			} else if (value == SHIPENNEMIE || value == SHIPALLY) {
				int dmg = Board[game.posPlayerY][game.posPlayerX]->getHp();
				Shipptr->takeDamage(dmg);
				game.nbEnnemie--;
				Debug::add_debug_nl("ship dmg - hp: ", Shipptr->getHp());
				Debug::add_debug_nl("ShipEnnemie destroy", game.nbEnnemie);
			}
			if (Shipptr->getHp() < 1)
				throw (-42);
			delete Board[game.posPlayerY][game.posPlayerX];
			Board[game.posPlayerY][game.posPlayerX] = Shipptr->clone();
		} else {
			Board[game.posPlayerY][game.posPlayerX] = Shipptr->clone();
		}
		delete Board[posPlayerY][posPlayerX];
		Board[posPlayerY][posPlayerX] = NULL;

		posPlayerY = game.posPlayerY;
		posPlayerX = game.posPlayerX;
	}

	if (game.shot) {
		ShipAlly *Shipptr = dynamic_cast<ShipAlly *>(Board[posPlayerY][posPlayerX]);
		// Debug::add_debug_nl("SHOOT y : ", game.posPlayerY - 1);
		// Debug::add_debug_nl("SHOOT x : ", game.posPlayerX);
		ABullet *Bulletptr = dynamic_cast<ABullet *>(Shipptr->shoot());
		if (!Bulletptr)
			throw (-42);
		if (Board[posPlayerY - 1][posPlayerX]) {
			int hp = Board[posPlayerY - 1][posPlayerX]->getHp();
			Board[posPlayerY - 1][posPlayerX]->takeDamage(Bulletptr->getDamage());
			Bulletptr->takeDamage(hp);
			if (Bulletptr->getHp() < 1) {
				delete Bulletptr;
				Bulletptr = NULL;
			}
		}
		game.newBoard[posPlayerY - 1][posPlayerX] = Bulletptr;
		game.shot = false;
		Debug::add_debug_nl("SHOOT type : ", (int)(game.newBoard[posPlayerY - 1][posPlayerX]->getType()));
	}

		// Debug::add_debug_nl("SHOOT x : ", game.posPlayerX);

	for (int y = 0; y < game.height; ++y) {
		for (int x = 0; x < game.width; ++x) {
			if (Board[y][x]){
				all_case(Board, game, y, x);
			}
		}
	}

	for (int y = 0; y < game.height; ++y) {
		for (int x = 0; x < game.width; ++x) {
			if (y == 1 && !game.newBoard[y][x] && random == x && iter-- == 0) {
				iter = NBDIFF;
				if (game.nbEnnemie >= game.maxEnnemie)
					continue;
				Debug::add_debug_nl("ShipEnnemie spawn", game.nbEnnemie);
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
