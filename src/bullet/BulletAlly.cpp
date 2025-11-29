#include "BulletAlly.hpp"
#include "struct.hpp"

BulletAlly::BulletAlly( void ) : ABullet(BULLETALLY, 1, 1){}

BulletAlly::BulletAlly(int damage, int hp) : ABullet(BULLETALLY, hp, damage) {}

BulletAlly::~BulletAlly( void ) {}

void	BulletAlly::clone(){}