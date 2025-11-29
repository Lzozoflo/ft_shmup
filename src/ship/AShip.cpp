
#include "AShip.hpp"

AShip::AShip( void ) : AGameEntity() {
    this->setType(SHIP);
}

AShip::AShip(t_type_AgameEntity type, int hp) : AGameEntity(type, hp) {}

AGameEntity * AShip::clone(void){
    return NULL;
}

AShip::~AShip( void ){
    
}

