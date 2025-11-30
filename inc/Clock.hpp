//
// Created by tjooris on 11/30/25.
//

#ifndef FT_SHMUP_CLOCK_HPP
#define FT_SHMUP_CLOCK_HPP

#include <ctime>

class Clock
{
	private:
		std::clock_t	_last;
	public:
		Clock( void );
		~Clock( void );
		float	getDeltaTime( void );
};

#endif //FT_SHMUP_CLOCK_HPP