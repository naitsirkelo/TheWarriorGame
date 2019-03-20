#ifndef __ENEMY_H
#define __ENEMY_H

#include "Enum.h"


class Enemy
{
private:
    int health, damage;
    EnemyType type;
public:
    Enemy(int eType);   // Make health be based on enemyType!
    EnemyType getType() {   return type;    }
    int getHealth() {       return health;  }
};

#endif
