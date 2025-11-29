#include "BulletEnnemie.hpp"
#include "struct.hpp"

BulletEnnemie::BulletEnnemie( void ) : ABullet(BULLETENNEMIE, 1, 1){}

BulletEnnemie::BulletEnnemie(int damage, int hp) : ABullet(BULLETENNEMIE, hp, damage) {}

BulletEnnemie::~BulletEnnemie( void ){}

AGameEntity * BulletEnnemie::clone(void){
    return NULL;
}