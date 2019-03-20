
#include "Player.h"
#include "Const.h"
#include "Enemy.h"
#include "Functions.h"
#include "HelpFunctions.h"
#include "ListTool2B.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <iomanip>
#include <string>

extern List* companions;


Player::Player()
{
    for (int i = 1; i <= MAXSKILLS; i++) { skills[i] = 1; }
    
    journal = new List(FIFO); notes = new List(FIFO);
    companion = nullptr;                // Set companion pointer to null
    clan = nullptr;
    difficulty = 15;                    // Set difficulty to normal
    hpUp = 5; stamUp = 5; manaUp = 10;  // Starting values for increasing stats
    constructed = false;                // Player not yet created
    started = false;
}


void Player::readFromFile(std::ifstream &in)
{
    in.getline(name, STRLEN);
    in.getline(race, STRLEN);
    in >> level;                       in.ignore();
    in >> health >> stamina >> mana;   in.ignore();
    in >> hpUp >> stamUp >> manaUp;    in.ignore();
    in >> xpreq >> xpcount;            in.ignore();
    in >> difficulty;                  in.ignore();
    for (int i = 1; i <= MAXSKILLS; i++) { in >> skills[i]; }
    constructed = true;
    std::cout << "\n\nPlayer info loaded from 'SAVEFILE.dta'!\n\n";
}


void Player::writeToFile(std::ofstream &out)
{
    out
    << name << "\n"
    << race << "\n"
    << level << "\n"
    << health << " " << stamina << " " << mana << "\n"
    << hpUp << " " << stamUp << " " << manaUp << "\n"
    << xpreq << " " << xpcount << "\n"
    << difficulty << "\n";
    for (int i = 1; i <= MAXSKILLS; i++) { out << skills[i] << " "; }
    std::cout << "\n\nPlayer info saved to 'SAVEFILE.dta'!\n\n";
}


void Player::createPlayer()
{
    char c[INLEN] = "";
    char n[STRLEN] = "";
    char r[STRLEN] = "";
    
    std:: cout
    << "\n\n -- - Create your character to begin the adventure! - --\n"
    << "\nEnter your desired name below...\n\n";
    readName("Name", n, STRLEN);
    
    strcpy(n,"");
    std::cout
    << "\n\nReally? This next attempt is final...\n\n";
    readName("Name", n, STRLEN);
    
    std::cout << "\n\nVery well! Your name is " << n << ".\n\n";
    strcpy(name,n);
    
    std::cout << "Now then, what is your race?\n\n";
    readName("Race", r, STRLEN);

    strcpy(r,"");
    std::cout
    << "\n\nWow, ok... Remember, your next attempt is final.\n\n";
    readName("Race", r, STRLEN);

    std::cout << "\n\nSo you´re of the " << r << " race, very well!\n\n";
    strcpy(race,r);
    
    std::cout << "\t(( When you see this arrow '->', hit Enter to continue. ))\n\n";
    waitForInput();
    
    std::cout
    << "As a newcomer to these lands your level is set to 1.\n"
    << "Complete quests and win battles to increase your level.\n\n"
    << "If you manage to survive, you will gain skillpoints. Use these wisely.\n\n";
    waitForInput();
    
    std::cout
    << "You´re getting a hang of this reading and writing thing, not bad!\n\n"
    << "Your first task is to divide 10 SP (skillpoints) between your skills,"
    << " based on your preferred playstyle.\n\n"
    << "Got it? Type 'ok' if you got it.\n\n";
    readCharArray("Command", c, INLEN);
    
    while (strcmp(c, "OK"))
    {
        std::cout << "\nWow... Let´s try that again.\n\n";
        strcpy(c,"");
        readCharArray("Command", c, INLEN);
    }
    
    std::cout
    << "\n\nGood job, now you can decide your stats.\n\n"
    << "Your base stats are 1, and your skills are:\n"
    << "Strength, Endurance, Intelligence, Charisma, Agility, Sorcery and Luck.\n\n";
    
    waitForInput();
    
    assignPoints(10);
    
    std::cout
    << "\n\n" << name << ", the " << race << " was successfully created!"
    << "\n\t(( Returning to main menu... ))\n\n\n\n";
    
    constructed = true;
}


void Player::playerInfo()
{
    std::cout
    << name << ", the " << race << ".\n"
    << "Level " << level << " :\t"
    << health << " HP\t"
    << stamina << " STAMINA\t\t"
    << mana << " MANA\n\n";
    
    if (companion) { companion->companionInfo(); }
}


void Player::showSkills()
{
    std::cout << "\n";
    for (int i = 1; i <= MAXSKILLS; i++)
    {
        int x = 17 - strlen(SKILLARRAY[i-1]);
        std::cout
        << "\t" << SKILLARRAY[i-1] << std::setw(x) << skills[i] << "\n";
    }
    std::cout << "\n";
}


void Player::showSkillsShort()
{
    std::cout << "\n";
    for (int i = 1; i <= MAXSKILLS; i++) { std::cout << SKILLARRAYSHORT[i-1] << " "; }
    std::cout << "\n ";
    for (int i = 1; i <= MAXSKILLS; i++) { std::cout << skills[i] << "   "; }
    std::cout << "\n ";
}


void Player::showAssignList()
{
    std::cout << "\n";
    for (int i = 1; i <= MAXSKILLS; i++)
    {
        int x = 17-strlen(SKILLARRAY[i-1]);
        std::cout
        << i << "\t" << SKILLARRAY[i-1] << std::setw(x) << skills[i] << "\n";
    }
    std::cout << "\n";
}


void Player::showAssignListShort()
{
    std::cout << "\n";
    for (int i = 1; i <= MAXSKILLS; i++) { std::cout << SKILLARRAYSHORT[i-1] << " "; }
    std::cout << "\n ";
    for (int i = 1; i <= MAXSKILLS; i++) { std::cout << i << "   "; }
    std::cout << "\n ";
}


void Player::showXpInfo()
{
    std::cout
    << "\n\t-<|  LEVEL " << level << "   " << xpcount << " / " << xpreq << " XP  |>-\n";
}


void Player::addCompanion(char* c)
{
    companion = (Companion*) companions->remove(c);
}


void Player::removeCompanion()
{
    std::cout << "\nYou lost your companion... \n";
    companion->getName(); std::cout << " has met their final resting place...\n\n";
    
    delete companion;
}


void Player::chooseDifficulty()
{
    std::cout
    << "\n (( You can change difficulty at a later stage. ))\n\n"
    << "-- -- Difficulty -- -- \n"
    << "\tEASY      : 1\n"
    << "\tNORMAL    : 2\n"
    << "\tHARD      : 3\n"
    << "\tCRAZYFACE : 4\n\n";
    int d = readInt("Command", 1, 4);
    
    std::cout << "\nSo... you set the difficulty to ";
    switch (d)
    {
        case 1: difficulty = DIFFEASY; std::cout << "Easy"; break;
        case 2: difficulty = DIFFNORM; std::cout << "Normal"; break;
        case 3: difficulty = DIFFHARD; std::cout << "Hard"; break;
        case 4: difficulty = DIFFCRAY; std::cout << "Crazyface"; break;
        default: break;
    }
    std::cout << "... That says alot about a person.\n\nVery well, continue.\n\n";
    
    waitForInput();
}


void Player::assignPoints(int p)
{
    int c = 0, hp = 0, st = 0, ma = 0;
    int i, j;
    
    int skillsUp[MAXSKILLS+1];
    for (j = 1; j <= MAXSKILLS; j++) { skillsUp[j] = 0; }
    
    std::cout << "\t(( Choose what skills to increase (1-7). Hit enter between each choice. ))\n";
    
    showAssignList();
    
    while (c < p)
    {
        std::cout << std::setw(30) << (p - c) << "\tSP left to place\n";
        int s = readNumber("Skill number: ", 1, 7);
        
        if (s == 2) { hp+=1; }
        else if (s == 5) { st+=1; }
        else if (s == 6) { ma+=1; }
        
        skillsUp[s] += 1;
        
        showAssignListShort();
        
        for (i = 1; i <= MAXSKILLS; i++) { std::cout << skills[i]+skillsUp[i] << "   "; }
        std::cout << "\n";
        
        c++;
    }
    for (j = 1; j <= MAXSKILLS; j++) { skills[j] += skillsUp[j]; }
    
    if (!constructed) {
        level = 1;
        xpcount = 0;
        xpreq = 100;
        health = 100 + (hp * hpUp);
        stamina = 100 + (st * stamUp);
        mana = 0 + (ma * manaUp);
    } else {
        health = health + (hp * hpUp);
        stamina = stamina + (st * stamUp);
        mana = mana + (ma * manaUp);
    }
    if (level > 1) { xpreq = xpreq * XPFACTOR; }
}


void Player::levelUp()
{
    ++level;
    xpcount = 0;
    std::cout
    << "\n- -- - Congratulations! You reached level " << level << "! - -- -\n\n"
    << "You get to improve your stats with 3 skillpoints.\n\n";
    waitForInput();
    assignPoints(3);
}


void Player::battle(int eType)
{
    Enemy* enemy = new Enemy(eType);
    
    char ch[INLEN] = " ";
    std::cout << "\t[  FIGHT\t\t|\tBATTLE ITEMS  ]\n\t[  ESCAPE\t|\tINVENTORY\t  ]\n\n";
    readCharArray("Choose option:", ch, INLEN);
    
    
//    std::cout << "\n-- - --  Battle Mode!  -- - --\n\n";
//
//    battleCommands();
//
//    int c = readInt("Battle command", 1, 8);
//
    
    while (strcmp(ch, "ESCAPE") && health >= 1 && enemy->getHealth() >= 1)
    {
        std::cout
        << "Your HP:\t" << health << "\tStamina: " << stamina << "\tMana: " << mana << "\n"
        << "Enemy HP:\t" << enemy->getHealth() << "\n"
        << "\n1 - Attack (10 stamina)\n"
        << "2 - Heavy Attack (20 stamina)\n"
        << "3 - Shield (5 stamina)\n"
        << "4 - Cast spell\n"
        //        cout << "5 - Use potion (0 stamina)" << endl;
        //        cout << "6 - Use mana potionenemyType (0 stamina)" << endl;
        << "5 - Do nothing (0 stamina)\n"
        //        cout << "6 - Attempt to flee (20 stamina)\n" << endl;
        << "Command: ";
//        cin >> battleCommand;
//        cout << endl;
//
//        if (battleCommand == 1)         //ATTACK
//        {
//            damageAtck = damageAtck * posSkills[0];
//            enemyHP[randomEnemy]-=damageAtck;
//            playerHP-=enemyAtck;
//            playerStam-=10;
//            cout << "You attack fiercly, dealing " << damageAtck << " damage!" << endl;
//            PrintLine();
//            damageAtck=damageAtck / posSkills[0];
//        }
//        else if (battleCommand == 2)    //HEAVY ATTACK
//        {
//            damageHvy=damageHvy * posSkills[0];
//            enemyHP[randomEnemy]-=damageHvy;
//            playerHP-=enemyAtck;
//            playerStam-=20;
//            cout << "You attack heavily, dealing " << damageHvy << " damage!" << endl;
//            PrintLine();
//            damageHvy=damageHvy / posSkills[0];
//        }
//        else if (battleCommand == 3)    //SHIELD
//        {
//            playerHP-=(enemyAtck/3);
//            playerStam-=5;
//        }
//        else if (battleCommand == 4)    //USE SPELL
//        {
//            damageSpl=damageSpl * posSkills[2];
//            enemyHP[randomEnemy]-=damageSpl;
//            playerHP-=enemyAtck;
//            playerMana-=10;
//            damageSpl=damageSpl / posSkills[2];
//        }
//        else if (battleCommand == 5)    //DO NOTHING
//        {
//            playerHP-=enemyAtck;
//        }
//        else{
//            cout << "Defeat the enemy before you´re defeated yourself!" << endl;
//        }
//    }
//
//    if (playerHP < 1 && enemyHP[randomEnemy] < 1){
//
//        cout << "You managed to defeat your enemy, but lost your life in the process." << endl;
//        cout << "Eternal glory awaits in the Aftertime." << endl;
//        PrintSpace();
//    }
//    else if (enemyHP[randomEnemy] < 1){
//
//        cout << "You defeated the " << enemy[randomEnemy] << "!\n" << endl;
//        cout << "Generations to come will surely sing songs of this brave battle!" << endl;
//        PrintSpace();
//    }
//    else if (playerHP < 1){
//
//        cout << "You were defeated in battle, and the " << enemy[randomEnemy];
//        cout << " was victorious.\nAn Aftertime in darkness awaits." << endl;
//        PrintSpace(); PrintDeath();
    }
}


void Player::openJournal()
{
    int c = 4;
    
    std::cout
    << "-- -- Journal -- -- \n"
    << "\tView quests       : 1\n"
    << "\tView notes        : 2\n"
    << "\tWrite a new note  : 3\n"
    << "\tExit journal      : 0\n\n";
    c = readInt("Command", 0, 3);
    
    while (c != 0)
    {
        switch (c)
        {
            case 1: journal->displayList(); break;
            case 2: notes->displayList();   break;
            default: break;
        }
        c = 4;
        c = readInt("Command", 0, 3);
    }
}

 
