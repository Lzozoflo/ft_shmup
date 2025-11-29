#include "ABullet.hpp"

ABullet::ABullet( void ) : AGameEntity(), _damage(1), _hp(1) {
	this->setType(BULLET);
}

ABullet::~ABullet( void ){

}