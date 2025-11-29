#include "ABullet.hpp"

ABullet::ABullet( void ) : AGameEntity(), _damage(1) {
	this->setType(BULLET);
}

ABullet::ABullet(t_type_AgameEntity type, int hp, int damage) : AGameEntity(type, hp), _damage(damage) {}

ABullet::~ABullet( void ){}