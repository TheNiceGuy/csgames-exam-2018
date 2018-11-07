#include "Garden.h"

#include <string>
#include <typeinfo>

#include "Pepper.h"
#include "Carot.h"


Garden::Garden(int nbPeppers, int nbCarots)
{
    _nbVegetables = 0;

    for(int i = 0; i < nbPeppers; ++i)
    {
        _vegetables[i] = new Pepper("Red");
    }

    for(int i = 0; i < nbCarots; ++i)
    {
        _vegetables[i] = new Carot();
    }

}

void Garden::addPepper(std::string couleur)
{
    _vegetables[_nbVegetables] = new Pepper(couleur);
    _nbVegetables++;
}

void Garden::addCarot()
{
    _vegetables[_nbVegetables] = new Carot();
    _nbVegetables++;
}

void Garden::removeDeadVegetables(int temperature)
{
    for(int i = 0; i < _nbVegetables; ++i)
    {
        if(!_vegetables[i]->isAlive(temperature))
        {
            --_nbVegetables;
        }
    }
}

void Garden::giveWater()
{
    for(int i = 0; i < _nbVegetables; ++i)
    {
        if(typeid(*_vegetables[i]).name() == typeid(Pepper).name())
            _vegetables[i]->giveWater((100-_vegetables[i]->getWater())/2);
        else
            _vegetables[i]->giveWater((100-_vegetables[i]->getWater())/5);
    }
}

void Garden::giveSunlight()
{
    for(int i = 0; i < _nbVegetables; ++i)
    {
        if(!_vegetables[i]->getSunlightTime() > 0)
        {
            if(typeid(*_vegetables[i]).name() == typeid(Pepper).name())
                _vegetables[i]->giveSunlight((100-_vegetables[i]->getSunlight())/3);
            else
                _vegetables[i]->giveSunlight((100-_vegetables[i]->getSunlight()));
        }

    }
}

std::string Garden::allToString()
{
    std::string a = "";
    for(int i = 0; i < _nbVegetables; ++i)
        a += _vegetables[i]->toString() + "\n";
    return a;
}

bool Garden::isEmpty()
{
    return _nbVegetables == 0;
}

void Garden::exist(int temperature)
{
    for(int i = 0; i < _nbVegetables; ++i)
        _vegetables[i]->exist(temperature);
}

Garden::~Garden()
{
    delete _vegetables;
}
