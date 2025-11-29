
#include "ShipAlly.hpp"
#include "AShip.hpp"

ShipAlly::ShipAlly( void ) : AShip() {
    this->setType(SHIPALLY);
}


AGameEntity *ShipAlly::clone(void){
    return NULL;
}



ShipAlly::~ShipAlly( void ){
    
}

