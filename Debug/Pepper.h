#ifndef PEPPER_H
#define PEPPER_H

#include <string>

#include "Vegetable.h"

class Pepper : public Vegetable
{
private:
	const std::string NAME = "Pepper";
	std::string _color;

public:
	Pepper(std::string color);

	bool isAlive(int temperature);

	void giveWater(int seconds);
	void giveSunlight(float hours);
	void exist(int temperature);

	std::string toString();
};

#endif
