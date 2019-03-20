#ifndef __CONSUMABLE_H
#define __CONSUMABLE_H

#include "ListTool2B.h"
#include "Enum.h"


class Consumable : public TextElement
{
private:
    ConsumableType type;
    int health;
    int stamina;
    int mana;
public:
    Consumable(char n[], int h, int s, int m, int c);
    void showInfo();
};

#endif
