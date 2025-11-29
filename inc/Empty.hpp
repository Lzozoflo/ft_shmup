

#ifndef EMPTY_HPP
#define EMPTY_HPP

#include "AGameEntity.hpp"

class Empty : public AGameEntity {

	private:

	public:
		Empty( void );
		virtual AGameEntity * clone();
		virtual ~Empty( void );

};



#endif
