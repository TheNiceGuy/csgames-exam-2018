#include "Pepper.h"

#include <string>

Pepper::Pepper(std::string color)
{
	_color = color;
	_water = 100;
	_sunlight = 100;
	_idealTemperature = 10;
	_isAlive = true;
}

bool Pepper::isAlive(int temperature)
{
	bool waterOK = _water > 0 && _water <= 100;
	bool sunlightOK = _sunlight > 0 && _sunlight <= 100;
	bool temperatureOK = temperature >= _idealTemperature - 10 && temperature <= _idealTemperature + 10;

	_isAlive = _isAlive && waterOK && sunlightOK && temperatureOK;

	return _isAlive;
}

void Pepper::giveWater(int seconds)
{
	_water += seconds * 2;
}

void Pepper::giveSunlight(float hours)
{
	_sunlightTime = hours;
}

void Pepper::exist(int temperature)
{
	_water -= 17;
	if(_sunlightTime <= 0)
		_sunlight -= 10;
	else
	{
		_sunlight += 3;
		_sunlightTime -= 1;
	}
	isAlive(temperature);
}

std::string Pepper::toString()
{
	return std::string("Name: ") + NAME + " " + Vegetable::toString();
}
