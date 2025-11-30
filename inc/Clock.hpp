//
// Created by tjooris on 11/30/25.
//

#ifndef CLOCK_HPP
#define CLOCK_HPP

#include <ctime>

class Clock
{
	private:
		std::clock_t	_last;
		struct timeval	_start;
		struct timeval	_current;
	public:
		Clock( void );
		~Clock( void );
		float	getDeltaTime( void );
		int		getTimeSinceStart( void );
		int	getMinutesSinceStart( void );
		void	reset( void );
		void	fpsLimit( float fps );
};

#endif