

#ifndef SHIPALLY_HPP
#define SHIPALLY_HPP

#include "AShip.hpp"

class ShipAlly : public AShip {

	private:

	public:
		ShipAlly( void );
		virtual AGameEntity * clone();
		~ShipAlly( void );

};



#endif
