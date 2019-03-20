//
//  TheWarrior.cpp
//  Programkjoring
//
//  Created by Ole K Larsen on 31/08/2017.
//  Refactoring: 10/06/2018
//  Copyright © 2017 user. All rights reserved.
//

#include "Player.h"
#include "Functions.h"
#include "HelpFunctions.h"
#include "Enum.h"

#include <iostream>
#include <string>

//void Explore();
//void ActOne();
//void ApproachGuard();
//void PrintQuestObtained();
//void VillageOne();
//void Forest();
//void ChooseAction();
//void PrintDeath();

Player player;

List* potions;
List* food;
List* companions;
List* clans;


int main()
{
    potions =    new List(Sorted);
    food =       new List(Sorted);
    companions = new List(Sorted);
    clans =      new List(Sorted);
    
    title();
    
    welcomeScreen();
    menuPlayerNotCreated();
    
    char c[INLEN] = ""; readCharArray("Command", c, INLEN);
    
    while (strcmp(c,"QUIT"))
    {
        if (!strcmp(c,"CREATE") || !strcmp(c,"CHARACTER"))
        {
            if (!player.created()) {
                player.createPlayer();
            } else {
                std::cout << "\n\nPlayer already exists:\n\n";
                player.playerInfo();
            }
        }
        else if (!strcmp(c,"DIFFICULTY"))
        {
            player.chooseDifficulty();
        }
        else if (!strcmp(c,"LORE"))
        {
            writeLore();
        }
        else if (!strcmp(c,"SAVE") || !strcmp(c,"SAVE GAME"))
        {
            saveGame();
        }
        else if (!strcmp(c,"LOAD") || !strcmp(c,"LOAD GAME"))
        {
            if (!player.created())
            {
                loadGame();
                player.showXpInfo();
            } else {
                std::cout
                << "\n\nFile already loaded... "
                << "Thank you, come again.\n\n";
            }
        }
        else if (!strcmp(c,"BEGIN") || !strcmp(c, "START"))
        {
            player.setStarted();
            std::cout << "Begin the thing...\n\n";
            adventure(1);
        }
        else if (!strcmp(c,"SKILLS") || !strcmp(c, "SHOW SKILLS"))
        {
            player.showSkills();
        }
        else if (!strcmp(c,"LEVEL"))
        {
            player.levelUp();
        }
        else if (!strcmp(c,"MENU"))
        {
            spacing(2);
            std::cout << "Yes, you´re already at the menu...";
            spacing(2);
        }

        if (!player.created())      menuPlayerNotCreated();
        else if (player.created())  menuPlayerCreated();
        else if (player.created() && player.startedAdventure()) menuStartedAdventure();
        
        strcpy(c, ""); readCharArray("Command", c, STRLEN);
    }
    
    return 0;
}

//
//void Explore()
//{
//    cout << "So you´re curious about the world of Eshance?"
//            "Very well, take a look around." << endl;
//    cout << "By now you should know how entering a command works.\n" << endl;
//    cout << "You can visit the following places.\n" << endl;
//    cout << "Icebridge Village." << endl;
//    cout << "Greywood Forest." << endl;
//    cout << "Western Bandit Cavern." << endl;
//    cout << "Dungeons of the Isclance Capitol\n" << endl;
//    cout << "Command: ";
//    cin >> placeInput;


//
//
//void VillageOne(){
//
//    string villageInput = "a";
//    PrintSpace();
//    cout << "You enter the village known as Uldviga. You know this because it says ";
//    cout << "Uldviga on the sign as you enter.\nYou´re no psychic, so remember to read the signs.\n" << endl;
//    cout << "The town is full of life, with townsfolk all over, everyone preparing for the long winter." << endl;
//    cout << "What will you do?" << endl;
//    cout << "Command: "; cin >> villageInput;
//
//}
//
//

//
//
//void ChooseAction(){
//
//    string actionInput = "a";
//    cout << "What will you do next?" << endl;
//    cout << " - Find a place to 'sleep'." << endl;
//    cout << " - Look for 'food'." << endl;
//    cout << " - 'talk' to the nearest person." << endl;
//    cout << " - Open 'journal'." << endl;
//
//    do{
//        cout << "Command: "; cin >> actionInput;
//    }while(actionInput!="sleep" && actionInput!="food" &&
//           actionInput!= "journal" && actionInput!= "talk");
//
//}
//
//
//
//
//
//void PrintQuestObtained(){
//
//    string obtainedInput = "a";
//
//    cout << "\n<><><> New Quest added to Journal <><><> " << endl;
//    cout << "\nEnter 'journal' to view quests or enter 'continue'." << endl;
//    do{
//        cout << "Command: "; cin >> obtainedInput;
//    }while(obtainedInput!= "journal" && obtainedInput!= "continue");
//
//    if(obtainedInput=="journal"){
//        OpenJournal();
//    }
//}
//
//

//
//void Levelup(){
//
////    LEVELUP COMMANDS
//    string levelCommand = "a";
////    int strength = 1; int endurance = 2; int intelligence = 3;
////    int charisma = 4; int agility = 5; int sorcery = 6; int luck = 7;
////    int numberArray[]={0,1,2,3,4,5,6};
//    string abbriArray[]={"str","end","int","chr","agi","src","lck"};
//    bool levelCheck = false;
//
//    PrintLine();
//    cout << "You have 1 skill point to spend." << endl;
//    cout << "Your current skills are ";
//
//    PrintSkills();
//
//    do{
//        cout << "Choose a skill to increase. Use skill abbreviations (lower case)." << endl;
//        cout << "Command: "; cin >> levelCommand;
//        for (int h = 0 ; h < MAXSKILLS ; h++){
//            if (levelCommand==abbriArray[h]){
//                levelCheck=true;
//                break;
//            }
//        }
//    }while(levelCheck==false);
//
//    if (levelCheck){
//
//        for (int m = 0 ; m < MAXSKILLS ; m++){
//            if (levelCommand == abbriArray[m]){
//                posSkills[m]+=ONEPOINT; break; }
//        }
//    }
//    PrintSpace(); cout << "Your skills are now: "; PrintSkills();
//    while(levelCommand!="continue"){
//        cout << "Type 'continue' to.. well.. continue.\nCommand: "; cin >> levelCommand;
//    }
//}
//
//

//
//
//
//
//void PrintDeath(){
//
//    string deathInput = "a";
//    cout << "You´ve met with a terrible fate, haven´t you? (Zelda reference)\n" << endl;
//    cout << "What do you want to do now?" << endl;
//    cout << "\tContinue in the last 'forest' (-1 to all skillpoints)." << endl;
//    cout << "\tContinue from the last 'village' (-1 to all skillpoints)." << endl;
//    cout << "\tReturn to 'menu'.\n\t'quit' the game" << endl;
//
//    do{
//        cout << "Command: "; cin >> deathInput;
//    }while(deathInput!="forest" && deathInput!="village" && deathInput!="menu"
//           && deathInput!="quit");
//
//    if(deathInput=="forest"){ Forest(); }
//    else if(deathInput=="village"){ VillageOne(); }
//    else if(deathInput=="menu"){ MenuScreen(); }
//
//}

