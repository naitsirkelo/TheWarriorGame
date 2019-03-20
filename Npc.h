#ifndef __NPC_H
#define __NPC_H

#include "Const.h"


class Npc
{
private:
    char name[STRLEN];
    char race[STRLEN];
    int health;
    int damage;
public:
    Npc(char n[], char r[]);
};

#endif
