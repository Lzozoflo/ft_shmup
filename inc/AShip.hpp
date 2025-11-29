

#ifndef ASHIP_HPP
#define ASHIP_HPP

#include "AGameEntity.hpp"

class AShip : public AGameEntity {
	protected:

	public:
		AShip( void );
		AShip(t_type_AgameEntity type, int hp);
		virtual AGameEntity * clone() = 0;
		virtual ~AShip( void );
		virtual AGameEntity * shoot() = 0;
};

#endif
