#include "ShipEnnemie.hpp"
#include "BulletEnnemie.hpp"
#include "Debug.hpp"

#include <cstdlib>

ShipEnnemie::ShipEnnemie( void ) : AShip(SHIPENNEMIE, 2), _randshoot(std::rand() % RANDSHOOT)  {}

ShipEnnemie::ShipEnnemie(const ShipEnnemie &other) : AShip(SHIPENNEMIE, other._hp), _randshoot(other._randshoot) {}

AGameEntity *ShipEnnemie::clone(void){
    return new ShipEnnemie(*this);
}

bool ShipEnnemie::canIShoot(int &randShootTick){
	// Debug::add_debug_nl("ennemie peu shoot");
	return (this->_randshoot == randShootTick);
}

ShipEnnemie::~ShipEnnemie( void ) {}

AGameEntity * ShipEnnemie::shoot(){
    return new BulletEnnemie();
}
