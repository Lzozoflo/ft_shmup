//
// Created by tjooris on 11/30/25.
//

#include "Clock.hpp"
#include <unistd.h>

Clock::Clock( void ) {
	this->_last = std::clock();
}

Clock::~Clock( void ) {}

float	Clock::getDeltaTime( void ) {
	std::clock_t	current = std::clock();
	float	deltaTime = float(current - this->_last) / CLOCKS_PER_SEC;
	this->_last = current;
	return deltaTime;
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
