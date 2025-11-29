
#ifndef STRUCT_HPP
#define STRUCT_HPP

class AGameEntity;
#include <vector>

typedef enum e_type_AGameEntity
{
	UNKNOWN = 0,
	EMPTY = ' ',
	BULLET = '0',
	BULLETALLY = '*',
	BULLETENNEMIE = '+',
	SHIP = '1',
	SHIPALLY = 'A',
	SHIPENNEMIE = 'V',
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