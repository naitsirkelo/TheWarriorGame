
#include "Clan.h"

#include <iostream>
#include <fstream>
#include <string>


Clan::Clan(std::ifstream &inn, char* n)
{
    strcpy(name, n);
}


void Clan::clanInfo()
{
    std::cout
    << "\n\tThe " << name << ".\n";
}




