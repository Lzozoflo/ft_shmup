

#ifndef BULLETENNEMIE_HPP
#define BULLETENNEMIE_HPP

#include "ABullet.hpp"

class BulletEnnemie : public ABullet {

	private:

	public:
		BulletEnnemie( void );
		virtual ~BulletEnnemie( void );
		virtual void clone();
};



#endif
