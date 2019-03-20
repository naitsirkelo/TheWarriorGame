#ifndef __COMPANION_H
#define __COMPANION_H

#include <fstream>


class Companion
{
private:
    char* name;
    char* race;
    int health;
    float damage;
public:
    Companion(std::ifstream &inn, char* n, char* r);
    void companionInfo();
    void setDmg(float d);
    void getName();
};

#endif
