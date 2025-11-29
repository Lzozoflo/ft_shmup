

#ifndef ASHIP_HPP
#define ASHIP_HPP

#include "AGameEntity.hpp"

class AShip : public AGameEntity {

	protected:

	public:
		AShip( void );
		virtual AGameEntity * clone() = 0;
		virtual ~AShip( void );
};



#endif
