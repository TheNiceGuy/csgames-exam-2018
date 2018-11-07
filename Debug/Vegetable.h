#ifndef VEGETABLE_H
#define VEGETABLE_H

#include <string>
#include "Garden.h"

class Vegetable
{
private:
	int _water;
	int _sunlight;
	int _idealTemperature;
	bool _isAlive;
	float _sunlightTime;

public:
	bool isAlive(int temperature);
	int getWater();
	int getSunlight();
	int getSunlightTime();

	void giveWater(int seconds);
	void giveSunlight(float hours);
	void exist(int temperature);

	std::string toString();
	
};

#endif
