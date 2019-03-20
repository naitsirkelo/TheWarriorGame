
#include "ListTool2B.h"
#include "Consumable.h"
#include "Enum.h"

#include <iostream>
#include <cstring>


Consumable::Consumable(char* n, int h, int s, int m, int c) : TextElement(n)
{
    health = h;
    stamina = s;
    mana = m;
    
    switch (c)
    {
        case 1: type = Food;        break;
        case 2: type = Water;       break;
        case 3: type = Natural;     break;
        case 4: type = Beverage;    break;
        case 5: type = Potion;      break;
        default: break;
    }
}


void Consumable::showInfo()
{
    std::cout << "\t" << text << "\n";
    if (health != 0)  { std::cout << "\t\tHealth : " << health << "\n"; }
    if (stamina != 0) { std::cout << "\t\tStamina : " << stamina << "\n"; }
    if (mana != 0)    { std::cout << "\t\tMana : " << mana << "\n\n"; }
}




