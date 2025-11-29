
#include "ShipAlly.hpp"
#include "AShip.hpp"
#include "Debug.hpp"

ShipAlly::ShipAlly( void ) : AShip(SHIPALLY, 10) {}

ShipAlly::ShipAlly(int hp) : AShip(SHIPALLY, hp) {}

AGameEntity *ShipAlly::clone(void){
    return new ShipAlly(this->_hp);
}

ShipAlly::~ShipAlly( void ){
    
}

