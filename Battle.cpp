
#include "Battle.h"
#include "Player.h"
#include "HelpFunctions.h"

#include <iostream>


void battle()
{
    std::cout << "\n-- - --  Battle Mode!  -- - --\n\n";
    
    battleCommands();
    
    int c = readInt("Battle command", 1, 8);
    
}


void battleCommands()
{
    std::cout
    << "\tAttack          : 1\n"
    << "\tHeavy Attack    : 2\n"
    << "\tDefend          : 3\n"
    << "\tUse spell       : 4\n"
    << "\tUse potion      : 5\n"
    << "\tUse mana potion : 6\n"
    << "\tDo nothing      : 7\n"
    << "\tRun away        : 8\n\n";
}

//    int playerHP = 15000, playerStam = 250, playerMana = 100;
////    int enemyHP = 1000;
//    int damageAtck = 1500, damageHvy = 2000, damageSpl = 3000, enemyAtck = 1500;

////    int totalEnemies = 10;
//    int enemyHP[10] = { 800 , 400 , 1000 , 1200 , 1100 , 900 , 500 , 1500 , 600 , 900};
//    playerHP = 15000;   //Setter hp til 15k naar command er battle. Hvis ikke avsluttes battle med en gang.
//
//    //Defend = ta halvparten av damagen.
//    //Stamina draines for hvert angrep.
//    //Heavy attack drainer mer damage.
//    //Sorcery tar mana.
//    //Start av adventure: lærer fireball fra en tidlig quest?
//
//    //char enemy[9][10] = { "Ghost" , "Chicken" , "Direwolf" , "Giant" , "Troll" , "Murderer" ,
//    //"Sheep" , "Tree" , "Fisherman" };
//    //int enemyHP[9] = { 800 , 400 , 1000 , 1200 , 1100 , 900 , 500 , 1500 , 600 };
//
//    srand(time(NULL));
//    int randomEnemy = ((rand() % 10));
//
//    if(enemyGuard){ randomEnemy=9; }
//    Enemy pirate = {500, 1, "50 gold.", 20};
//
//    enemyHP[randomEnemy] = enemyHP[randomEnemy] * difficulty;
//
//    PrintLine();
//    cout << "You have been challenged by a " << enemy[randomEnemy] << " to a battle!\n" << endl;



