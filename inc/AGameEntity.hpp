

#ifndef AGAMEENTITY_HPP
#define AGAMEENTITY_HPP


#include <string>

typedef enum e_type_AGameEntity
{
	EMPTY,
	BULLETALLY,
	BULLETENNEMIE,
	SHIPALLY,
	SHIPENNEMIE,
} t_type_AgameEntity;


class AGameEntity {

	private:

		t_type_AgameEntity type;

	public:
		AGameEntity( void );
		virtual void idk() = 0;
		virtual ~AGameEntity( void );

};



#endif
