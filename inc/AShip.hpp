

#ifndef ASHIP_HPP
#define ASHIP_HPP

#include "AGameEntity.hpp"

class AShip : protected AGameEntity {

	private:
		int	_hp;

	public:
		AShip( void );
		virtual void idk() = 0;
		virtual ~AShip( void );

};



#endif
