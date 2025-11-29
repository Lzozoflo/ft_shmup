

#ifndef BULLETENNEMIE_HPP
#define BULLETENNEMIE_HPP

#include "ABullet.hpp"

class BulletEnnemie : public ABullet {

	private:

	public:
		BulletEnnemie( void );
		BulletEnnemie(int damage, int hp);
		virtual ~BulletEnnemie( void );
		virtual AGameEntity * clone();
};



#endif
