
#include "AShip.hpp"

AShip::AShip( void ) : AGameEntity() {
    this->setType(SHIP);
}

AGameEntity * AShip::clone(void){
    return NULL;
}

AShip::~AShip( void ){
    
}

