

#ifndef BULLETALLY_HPP
#define BULLETALLY_HPP

#include "ABullet.hpp"

class BulletAlly : public ABullet {

	private:
	public:
		BulletAlly( void );
		virtual ~BulletAlly( void );
		virtual void clone();
};

#endif
