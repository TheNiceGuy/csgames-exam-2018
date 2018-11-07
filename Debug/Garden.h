#ifndef GARDEN_H
#define GARDEN_H

#include <string>
#include "Vegetable.h"

class Garden
{
private:
	Vegetable* _vegetables[10];
    int _nbVegetables;

public:
	Garden(int nbPeppers, int nbCarots);
    ~Garden();

    void addPepper(std::string couleur);
    void addCarot();

    void removeDeadVegetables(int temperature);

    bool isEmpty();

    void giveWater();
    void giveSunlight();
    void exist(int temperature);

    std::string allToString();
};

#endif
