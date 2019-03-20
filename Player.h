#ifndef __PLAYER_H
#define __PLAYER_H

#include "ListTool2B.h"
#include "Const.h"
#include "Clan.h"
#include "Companion.h"

#include <fstream>
#include <iostream>


class Player
{
private:
    char name[STRLEN], race[STRLEN];
    
    int skills[MAXSKILLS+1];
    int level;
    int health, stamina, mana;
    
    float xpcount, xpreq;
    
    List* journal;
    List* notes;
    Companion* companion;
    Clan* clan;
    
    int difficulty;
    int hpUp, stamUp, manaUp;
    
    bool constructed, started;
    
public:
    Player();
    void writeToFile(std::ofstream &out);
    void readFromFile(std::ifstream &in);
    void createPlayer();
    void playerInfo();
    void showSkills();
    void showSkillsShort();
    void showAssignList();
    void showAssignListShort();
    void showXpInfo();
    void addCompanion(char* c);
    void removeCompanion();
    void chooseDifficulty();
    void assignPoints(int p);
    void levelUp();
    void battle(int eType);
    void openJournal();
    void testWrite() { std::cout << "\n" << xpcount << "\n"; }
    
    void increaseSkill(int sk, int val) { skills[sk] += val; };
    bool startedAdventure() {   return started;     }
    void setStarted() {         started = true;     }
    bool created() {            return constructed; }
    char* getName() {           return name;        }
    char* getRace() {           return race;        }
    int getSkillValue(int s) {  return skills[s];   }
};

#endif
