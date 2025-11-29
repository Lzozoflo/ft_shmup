

#ifndef BULLETALLY_HPP
#define BULLETALLY_HPP

#include "ABullet.hpp"

class BulletAlly : public ABullet {

	private:
	public:
		BulletAlly( void );
		BulletAlly(int damage, int hp);
		~BulletAlly( void );
		virtual AGameEntity * clone();
};

#endif
