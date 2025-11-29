
#ifndef STRUCT_HPP
#define STRUCT_HPP

class AGameEntity;
#include <vector>

typedef enum e_type_AGameEntity
{
	UNKNOWN = 0,
	EMPTY = 32,			// ' '
	BULLET = 48, 		// 0
	BULLETALLY = 42, 	// *
	BULLETENNEMIE = 43,	// +
	SHIP = 49,			// 1
	SHIPALLY = 65,		// A
	SHIPENNEMIE = 86,	// V
} t_type_AgameEntity;


typedef struct s_game
{
    int height;
    int width;
    int posPlayerX;
    int posPlayerY;
    std::vector<std::vector<AGameEntity *> > newBoard;
} t_game;


#endif