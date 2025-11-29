#include "ShipEnnemie.hpp"

ShipEnnemie::ShipEnnemie( void ) : AShip(SHIPENNEMIE, 1) {}

ShipEnnemie::ShipEnnemie(int hp) : AShip(SHIPENNEMIE, hp) {}

AGameEntity *ShipEnnemie::clone(void){
    return new ShipEnnemie(this->_hp);
}
