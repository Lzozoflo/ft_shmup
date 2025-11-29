

#ifndef SHIPENNEMIE_HPP
#define SHIPENNEMIE_HPP

#include "AShip.hpp"

class ShipEnnemie : public AShip {

	private:

	public:
		ShipEnnemie( void );
		ShipEnnemie(int hp);
		virtual AGameEntity * clone();
		~ShipEnnemie( void );
		virtual AGameEntity * shoot();
};



#endif
