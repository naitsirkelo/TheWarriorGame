#ifndef __CONST_H
#define __CONST_H

//  FUNCTIONALITY
const int STRLEN = 60;
const int INLEN = 30;
const int OUTLEN = 30;
const int NOTELEN = 80;
const int MAXSKILLS = 7;
const int ENEMIES = 10;
const float XPFACTOR = 1.1f;

struct Note
{  char info;
    bool completed;
    Note()  { completed = false; }   };

typedef Note* itemType;

//  DIFFICULTY
const int DIFFEASY = 11;
const int DIFFNORM = 15;
const int DIFFHARD = 20;
const int DIFFCRAY = 30;

//  WORLD NAMES
const char WOLD[STRLEN] =            "Eshance";
const char KINGDOM[STRLEN] =         "Isclance";
const char VILLAGE1[STRLEN] =        "Icebridge Village";
const char DUNGEONSCAPITOL[STRLEN] = "Dungeons of the Isclance Capitol";
const char FOREST1[STRLEN] =         "Frostpine Valley";

const char MENU[INLEN] = "MENU";
const char SKILLARRAY[MAXSKILLS][13] = {"Strength","Endurance","Intelligence","Charisma",
                                        "Agility","Sorcery","Luck"};
const char SKILLARRAYSHORT[MAXSKILLS][4] = {"STR","END","INT","CHA",
                                            "AGI","SRC","LCK"};
const char ENEMYARRAY[ENEMIES][10] = { "Human", "Giant", "Undead", "Troll", "Dragon",
                                       "Shark","Sheep", "Guard", "Ghost", "Tree" };
const int ENEMYHP[ENEMIES] = {  1000, 2000, 1300, 1600, 3000,
                                1500, 500,  1200, 2200, 5000 };
const int ENEMYDMG[ENEMIES] = { 100, 250, 100, 120, 200,
                                135, 25,  110, 150, 5   };

//  FOOD VALUES
const int ROOTS = 3;
const int MUSHROOMS = 5;
const int RABBITSMALL = 5;
const int RABBIT = 6;
const int RABBITLARGE = 7;
const int VEIRCROWEGGS = 9;
const int BEEF = 9;
const int SOUP = 7;
const int BREAD = 5;
const int WATER = 3;
const int MILK = 5;
const int CHICKEN = 7;
const int SALMON = 7;
const int SHARK = 9;

#endif
