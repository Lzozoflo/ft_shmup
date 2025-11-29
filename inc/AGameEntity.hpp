

#ifndef AGAMEENTITY_HPP
#define AGAMEENTITY_HPP


#include <string>

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


class AGameEntity {

	protected:

		t_type_AgameEntity _type;

	public:
		AGameEntity( void );
		virtual void idk() = 0;
		char	getType() const ;
		virtual ~AGameEntity( void );
		void	setType(t_type_AgameEntity type);

};



#endif
