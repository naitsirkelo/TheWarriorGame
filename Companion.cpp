
#include "Companion.h"

#include <iostream>
#include <fstream>
#include <cstring>


Companion::Companion(std::ifstream &inn, char* n, char* r)
{
    strcpy(name,n);
    strcpy(race,r);
    
    health = 100;
    damage = 0.f;
}


void Companion::companionInfo()
{
    std::cout
    << "Your companion is a " << race << ", " << name << ".\n"
    << health << " HP\t" << damage << " ATTACK POWER\n\n";
}


void Companion::setDmg(float d)
{
    damage = d;
}


void Companion::getName()
{
    std::cout << name;
}




