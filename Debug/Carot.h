#ifndef CAROT_H
#define CAROT_H

#include "Vegetable.h"

#include <string>

class Carot: public Vegetable
{
	const std::string NOM = "Carot";
public:
	Carot();

	bool isAlive(int temperature);

	void giveWater(int seconds);
	void giveSunlight(float hours);
	void exist(int temperature);

	std::string toString();
};

#endif
