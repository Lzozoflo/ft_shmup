#include "BulletEnnemie.hpp"
#include "struct.hpp"

#include <cstdlib>
BulletEnnemie::BulletEnnemie( void ) : ABullet(BULLETENNEMIE, 1, 1), _randshoot(std::rand() % RANDSHOOT) {}

BulletEnnemie::BulletEnnemie(const BulletEnnemie &other) : ABullet(BULLETENNEMIE, other._hp, other._damage), _randshoot(other._randshoot) {}

BulletEnnemie::~BulletEnnemie( void ){}

AGameEntity * BulletEnnemie::clone(void){
    return new BulletEnnemie(*this);
}
