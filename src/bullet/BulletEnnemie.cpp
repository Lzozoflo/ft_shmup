#include "BulletEnnemie.hpp"
#include "struct.hpp"

BulletEnnemie::BulletEnnemie( void ) : ABullet(BULLETENNEMIE, 1, 1){}

BulletEnnemie::BulletEnnemie(const BulletEnnemie &other) : ABullet(BULLETENNEMIE, other._hp, other._damage) {}

BulletEnnemie::~BulletEnnemie( void ){}


AGameEntity * BulletEnnemie::clone(void){
    return new BulletEnnemie(*this);
}
