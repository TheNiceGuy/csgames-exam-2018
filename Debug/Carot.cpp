#include "Carot.h"

#include <string>

Carot::Carot()
{
	_water = 100;
	_sunlight = 100;
	_idealTemperature = 25;
	_isAlive = true;
}

bool Carot::isAlive(int temperature)
{
	bool waterOK = _water > 0 && _water <= 100;
	bool sunlightOK = _sunlight > 0 && _sunlight <= 100;
	bool temperatureOK = temperature >= _idealTemperature - 15 && temperature <= _idealTemperature + 15;

	_isAlive = _isAlive && waterOK && sunlightOK && temperatureOK;

	return 	_isAlive;
}

void Carot::giveWater(int seconds)
{
	_water += seconds * 5;
}

void Carot::giveSunlight(float hours)
{
	_sunlightTime = hours;
}

void Carot::exist(int temperature)
{
	_water -= 8;
	if(_sunlightTime <= 0)
		_sunlight -= 4;
	else
	{
		_sunlight += 6;
		_sunlightTime -= 1;
	}
	isAlive(temperature);
}

std::string Carot::toString()
{
	return std::string("Nom: ") + NOM + " " + Vegetable::toString();
}
