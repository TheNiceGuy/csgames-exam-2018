#include "Vegetable.h"

#include <string>

std::string Vegetable::toString()
{
	return std::string("Alive: ") + std::string(_isAlive ? "True" : "False") + " Water: " + std::to_string(_water) +
		" Sunlight: " + std::to_string(_sunlight) + " Ideal Temperature: " +
		std::to_string(_idealTemperature);
}

int Vegetable::getWater()
{
	return _water;
}

int Vegetable::getSunlight()
{
	return _sunlight;
}

int Vegetable::getSunlightTime()
{
	return _sunlightTime;
}
