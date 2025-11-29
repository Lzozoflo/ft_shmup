

#ifndef SHIPENNEMIE_HPP
#define SHIPENNEMIE_HPP

#include "AShip.hpp"

class ShipEnnemie : public AShip {

	private:

	public:
		ShipEnnemie( void );
		~ShipEnnemie( void );
		virtual void clone();
};



#endif
