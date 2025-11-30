

#ifndef SHIPENNEMIE_HPP
#define SHIPENNEMIE_HPP

#include "AShip.hpp"
#define RANDSHOOT 500

class ShipEnnemie : public AShip {

	private:
		int _randshoot;
	public:
		ShipEnnemie( void );
		ShipEnnemie(const ShipEnnemie &other);
		bool canIShoot(int &randShootTick);
		virtual AGameEntity * clone();
		~ShipEnnemie( void );
		virtual AGameEntity * shoot();
};



#endif
