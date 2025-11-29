

#ifndef ABULLET_HPP
#define ABULLET_HPP

#include "AGameEntity.hpp"

class ABullet : public AGameEntity {

	protected:
		int	_damage;
	public:
		ABullet( void );
		ABullet(t_type_AgameEntity type, int hp, int damage);
		virtual AGameEntity * clone() = 0;
		virtual ~ABullet( void );
		int getDamage() const;
};

#endif
