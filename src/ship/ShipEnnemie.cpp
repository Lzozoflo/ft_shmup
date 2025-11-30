#include "ShipEnnemie.hpp"
#include "BulletEnnemie.hpp"

ShipEnnemie::ShipEnnemie( void ) : AShip(SHIPENNEMIE, 2) {}

ShipEnnemie::ShipEnnemie(int hp) : AShip(SHIPENNEMIE, hp) {}

AGameEntity *ShipEnnemie::clone(void){
    return new ShipEnnemie(this->_hp);
}

ShipEnnemie::~ShipEnnemie( void ) {}

AGameEntity * ShipEnnemie::shoot(){
    return new BulletEnnemie();
}
