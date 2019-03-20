
#include "Npc.h"

#include <iostream>
#include <string>


Npc::Npc(char n[], char r[])
{
    strcpy(name,n);
    strcpy(race, r);
    
    health = 100;
    damage = 0;
}




