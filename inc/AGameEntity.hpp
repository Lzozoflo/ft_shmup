

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
		virtual void idk() = 0;
		char	getType() const ;
		virtual ~AGameEntity( void );
		void	setType(t_type_AgameEntity type);

};



#endif
