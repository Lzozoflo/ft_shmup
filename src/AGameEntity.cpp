#include "AGameEntity.hpp"


AGameEntity::AGameEntity( void ) : _type(UNKNOWN), _hp(1) {}

AGameEntity::AGameEntity(t_type_AgameEntity type, int hp) : _type(type), _hp(hp) {}

AGameEntity::~AGameEntity( void ) {}

char	AGameEntity::getType() const {
    return (this->_type);
}

void	AGameEntity::setType(t_type_AgameEntity type) {
    this->_type = type;
}

int AGameEntity::getHp() const {
    return this->_hp;
}

void AGameEntity::takeDamage(int damage) {
    this->_hp -= damage;
}
