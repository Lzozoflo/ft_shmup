#include "AGameEntity.hpp"


AGameEntity::AGameEntity( void ) : _type(UNKNOWN) {

}

AGameEntity::~AGameEntity( void ) {

}

char	AGameEntity::getType() const {
    return (this->_type);
}

void	AGameEntity::setType(t_type_AgameEntity type) {
    this->_type = type;
}