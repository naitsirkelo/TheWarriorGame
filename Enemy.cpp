
#include "Enemy.h"
#include "Enum.h"
#include "Const.h"


Enemy::Enemy(int eType)
{
    switch (eType) {
        case 1: type = Human;   health = ENEMYHP[Human];    damage = ENEMYDMG[Human];
            break;
        case 2: type = Giant;   health = ENEMYHP[Giant];    damage = ENEMYDMG[Giant];
            break;
        case 3: type = Undead;  health = ENEMYHP[Undead];   damage = ENEMYDMG[Undead];
            break;
        case 4: type = Troll;   health = ENEMYHP[Troll];    damage = ENEMYDMG[Troll];
            break;
        case 5: type = Dragon;  health = ENEMYHP[Dragon];   damage = ENEMYDMG[Dragon];
            break;
        case 6: type = Shark;   health = ENEMYHP[Shark];    damage = ENEMYDMG[Shark];
            break;
        case 7: type = Sheep;   health = ENEMYHP[Sheep];    damage = ENEMYDMG[Sheep];
            break;
        case 8: type = Guard;   health = ENEMYHP[Guard];    damage = ENEMYDMG[Guard];
            break;
        case 9: type = Ghost;   health = ENEMYHP[Ghost];    damage = ENEMYDMG[Ghost];
            break;
        case 10:type = Tree;    health = ENEMYHP[Tree];     damage = ENEMYDMG[Tree];
            break;
        default:
            break;
    }
}




