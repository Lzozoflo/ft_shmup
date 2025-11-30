

#ifndef BULLETENNEMIE_HPP
#define BULLETENNEMIE_HPP

#include "ABullet.hpp"
#define RANDSHOOT 10

class BulletEnnemie : public ABullet {

	private:
		int _randshoot;
	public:
		BulletEnnemie( void );
		BulletEnnemie(const BulletEnnemie &other);
		virtual ~BulletEnnemie( void );
		virtual AGameEntity * clone();
};



#endif
