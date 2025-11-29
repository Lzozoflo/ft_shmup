
#include "Empty.hpp"

Empty::Empty( void ) : AGameEntity() {
    this->setType(EMPTY);
}


AGameEntity * Empty::clone(void){
    return NULL;
}


Empty::~Empty( void ){
    
}

