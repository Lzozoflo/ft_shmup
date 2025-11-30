
#ifndef STRUCT_HPP
#define STRUCT_HPP

#define GAMEOVER    3000000// dead screen loser
#define FPS6        160000// limit 6 fps
#define FPS30       32000// limit 30 fps
#define FPS60       16000// limit 60 fps
#define FPS120      8000// limit 120 fps
#define RUN	    1
#define EXIT	0

#define RANDSHOOT 50	// rand frame shoot
#define NBDIFF 2		// vitesse de spawn
#define BULLETMOVE 0	// rand frame bullet move
#define GAMELIFE 100	// rand frame bullet move



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
	int nbEnnemie;
	int maxEnnemie;
	bool shot;
	int gamelife;
} t_game;


#endif
