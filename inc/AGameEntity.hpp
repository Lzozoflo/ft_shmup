

#ifndef AGAMEENTITY_HPP
#define AGAMEENTITY_HPP


#include <string>
#include "struct.hpp"

class AGameEntity {

	protected:
		t_type_AgameEntity _type;
		int	_hp;
	public:
		AGameEntity( void );
		AGameEntity(t_type_AgameEntity type, int hp);
		virtual AGameEntity * clone() = 0;
		void takeDamage(int damage);
		int getHp() const;
		char	getType() const ;
		virtual ~AGameEntity( void );
		void	setType(t_type_AgameEntity type);

};



#endif
