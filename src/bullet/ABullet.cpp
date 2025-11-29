#include "ABullet.hpp"

ABullet::ABullet( void ) : AGameEntity(), _damage(1) {
	this->setType(BULLET);
}

ABullet::~ABullet( void ){

}