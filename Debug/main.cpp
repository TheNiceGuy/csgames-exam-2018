#include <string>
#include <iostream>

#include "Garden.h"

#define TEMPERATURE 30

int main()
{
    std::cout << "Gardening..." << std::endl;
    Garden garden(5,5);

    while(!garden.isEmpty())
    {
        garden.giveWater();
        garden.giveSunlight();
        garden.removeDeadVegetables(TEMPERATURE);
        garden.exist(TEMPERATURE);
        std::cout << garden.allToString() << std::endl;
        std::cin.get();
    }
}
