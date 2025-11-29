
#include "ShipAlly.hpp"
#include "AShip.hpp"
#include "Debug.hpp"

ShipAlly::ShipAlly( void ) : AShip() {
    this->setType(SHIPALLY);
}


AGameEntity *ShipAlly::clone(void){
    return new ShipAlly();
}



ShipAlly::~ShipAlly( void ){
    
}

