

#ifndef ABULLET_HPP
#define ABULLET_HPP

#include "AGameEntity.hpp"

class ABullet : public AGameEntity {

	private:

	public:
		ABullet( void );
		virtual void idk() = 0;
		virtual ~ABullet( void );

};



#endif
