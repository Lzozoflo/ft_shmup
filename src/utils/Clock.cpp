//
// Created by tjooris on 11/30/25.
//

#include "Clock.hpp"
#include <unistd.h>
#include <sys/time.h>

Clock::Clock( void ) {
	this->_last = std::clock();
	gettimeofday(&this->_start, NULL);
}

Clock::~Clock( void ) {}

float	Clock::getDeltaTime( void ) {
	std::clock_t	current = std::clock();
	float	deltaTime = float(current - this->_last) / CLOCKS_PER_SEC;
	this->_last = current;
	return deltaTime;
}

int	Clock::getTimeSinceStart( void ) {
	gettimeofday(&_current, NULL);
	int	seconds = _current.tv_sec - this->_start.tv_sec;
	int	useconds = _current.tv_usec - this->_start.tv_usec;
	return (seconds + useconds / 1000000);
}

int	Clock::getMinutesSinceStart( void ) {
	return this->getTimeSinceStart() / 60;
}

void	Clock::reset( void ) {
	this->_last = std::clock();
}

void	Clock::fpsLimit( float fps ) {
	float	frameTime = 1.0f / fps;
	float	deltaTime = this->getDeltaTime();

	if (deltaTime < frameTime) {
		usleep((frameTime - deltaTime) * 1000000);
	}
}
