

#ifndef ISHIP_HPP
#define ISHIP_HPP

#include "AGameEntity.hpp"

class IShip : public AGameEntity {

	private:
		int	_hp = 0;
		
	public:
		virtual ~IShip( void ) = 0;

};



#endif
