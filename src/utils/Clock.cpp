//
// Created by tjooris on 11/30/25.
//

#include "Clock.hpp"

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
