#ifndef __INVENTORY_H
#define __INVENTORY_H

#include "ListTool2B.h"


class Inventory
{
private:
    List* hpPotions;
    List* manaPotions;
    List* staminaPotions;
    List* foodItems;
public:
    Inventory();
};

#endif
