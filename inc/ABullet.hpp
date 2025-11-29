

#ifndef ABULLET_HPP
#define ABULLET_HPP

#include "AGameEntity.hpp"

class ABullet : public AGameEntity {

	protected:
		int	_damage;
	public:
		ABullet( void );
		virtual void clone() = 0;
		virtual ~ABullet( void );
};



#endif
