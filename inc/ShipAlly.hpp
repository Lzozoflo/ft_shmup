

#ifndef SHIPALLY_HPP
#define SHIPALLY_HPP

#include "AShip.hpp"

class ShipAlly : public AShip {

	private:

	public:
		ShipAlly( void );
		ShipAlly(int hp);
		virtual AGameEntity * clone();
		~ShipAlly( void );
		virtual AGameEntity * shoot();

};



#endif
