
#include "Functions.h"
#include "HelpFunctions.h"
#include "Player.h"
#include "Enum.h"

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

extern Player player;


void title()
{
//    std::cout
//    << " _______ _    _ ______\n"
//    << "|__   __| |  | |  ____|\n"
//    << "   | |  | |__| | |__\n"
//    << "   | |  |  __  |  __|\n"
//    << "   | |  | |  | | |____\n"
//    << "__ |_|  |_| _|_|______|_  _____  _____ ____  _____\n"
//    << "\ \        / /\   |  __ \|  __ \|_   _/ __ \|  __ \\n"
//    << " \ \  /\  / /  \  | |__) | |__) | | || |  | | |__) |\n"
//    << "  \ \/  \/ / /\ \ |  _  /|  _  /  | || |  | |  _  /\n"
//    << "   \  /\  / ____ \| | \ \| | \ \ _| || |__| | | \ \\n"
//    << "    \/  \/_/    \_\_|  \_\_|  \_\_____\____/|_|  \_\\n";
    
    std::cout
    << "888888888888  88        88  88888888888\n"
    << "     88       88        88  88\n"
    << "     88       88aaaaaaaa88  88aaaaa\n"
    << "     88       88''''''''88  88'''''\n"
    << "     88       88        88  88\n"
    << "     88       88        88  88888888888\n"
    << "\n"
    << "I8,        8        ,8I    db         88888888ba   88888888ba   88    ,ad8888ba,    88888888ba\n"
    << "`8b       d8b       d8'   d88b        88      '8b  88      '8b  88   d8''    `'8b   88      '8b\n"
    << "'I8,     ,8'8,     ,8'   d8'`8b       88      ,8P  88      ,8P  88  d8'        `8b  88      ,8P\n"
    << "  Y8     8P Y8     8P   d8'  `8b      88aaaaaa8P'  88aaaaaa8P'  88  88          88  88aaaaaa8P'\n"
    << "  `8b   d8' `8b   d8'  d8YaaaaY8b     88''''88'    88''''88'    88  88          88  88''''88'\n"
    << "   `8a a8'   `8a a8'  d8''''''''8b    88    `8b    88    `8b    88  Y8,        ,8P  88    `8b\n"
    << "    `8a8'     `8a8'  d8'        `8b   88     `8b   88     `8b   88   Y8a.    .a8P   88     `8b\n"
    << "     `8'       `8'  d8'          `8b  88      `8b  88      `8b  88    `'Y8888Y''    88      `8b\n\n";
}

void welcomeScreen()
{
    char c[INLEN] = "";
    std::cout
    << " - --- Welcome to this text based adventure! --- -\n\n"
    << "Use your keyboard to enter commands, read every line, and remember this... \n"
    << "Your best avaialable option may be something entirely different from what the screen tells you...\n\n\n\n"
    << "If you´re ready to begin, simply write 'menu' to go the menu. No tricks.\n\n";
    readCharArray("Command", c, STRLEN);
    
    while (strcmp(c, MENU))
    {
        strcpy(c,"");
        std::cout << "\nThis really shouldn´t be challenging.\n";
        readCharArray("Command", c, STRLEN);
    }
    std::cout
    << "\n\n\nWell done, that was quite the task!"
    << "\nThis is the main menu, you´re doing great so far.\n"
    << "\n\t(( Capitalization is not important, by the way... ))\n\n"
    << "You may choose an action from the following list:\n\n";
}


void menuPlayerNotCreated()
{
    std::cout << "\n\t\t\t- -- ~ < MAIN MENU > ~ -- -\n"
    << std::setw(22) << "Create character"  << std::setw(20) << "(input character)\n"
    << std::setw(22) << "Load saved game"   << std::setw(15) << "(input load)\n";
}


void menuPlayerCreated()
{
    std::cout << "\n\t\t\t- -- ~ < MAIN MENU > ~ -- -\n"
    << std::setw(22) << "Begin adventure"   << std::setw(16) << "(input begin)\n"
    //    << std::setw(22) << "Battle training"   << std::setw(17) << "(input battle)\n"
    << std::setw(22) << "Change difficulty" << std::setw(21) << "(input difficulty)\n"
//        << std::setw(22) << "Explore map"       << std::setw(18) << "(input explore)\n"
    << std::setw(22) << "Read lore"         << std::setw(15) << "(input lore)\n";
}


void menuStartedAdventure()
{
    std::cout << "\n\t\t\t- -- ~ < MAIN MENU > ~ -- -\n"
    //    << std::setw(22) << "Battle training"   << std::setw(17) << "(input battle)\n"
    << std::setw(22) << "Change difficulty" << std::setw(21) << "(input difficulty)\n"
    //    << std::setw(22) << "Explore map"       << std::setw(18) << "(input explore)\n"
    << std::setw(22) << "Read lore"         << std::setw(15) << "(input lore)\n";
}


void writeLore()
{
    std::cout
    << "--------------------------------------------------\n"
    << "This adventure is placed in the Realm Of Eshance, and the wintery"
    << "Kingdom Of Isclance.\n\n"
    << "The realm has been through a century of trouble, war and unlawfulness. "
    << "The winter has been long and unforgiving, bringing with it only"
    << "suffering for the common folk. \n";
    waitForInput();
    std::cout
    << "Spring is finally here, but this means that the bandit lords have"
    << "once again started to stake their"
    << " claims on the open roads.\n\nAs the nobility florishes and the"
    << "peasants and workers strive, the wedge "
    << "has been driven deeper than ever. Farmers boys and girls alike"
    << "join their bandit factions and seek to destroy "
    << "the lords and ladies of their land.\n";
    waitForInput();
    std::cout
    << "Within the bandit factions, "
    << "the highest regard is the claim for the title as Bandit King.\n\n"
    << "For the last eight winters the title has been held by"
    << "Mirvannis Staunewal Of The Grey Coast. "
    << "The northerner has had three assassination attempts on his life"
    << "only this winter, and the bandit lords know that "
    << "their time to strike is now.\n\nThe winter is nearing its end,"
    << "but as the spring brings warmth,"
    << " the king will have to be driven from his seat.\n"
    << "--------------------------------------------------\n";
    waitForInput();
}


void saveGame()
{
    std::ofstream out("SAVEFILE.dta");
    player.writeToFile(out);
}


void loadGame()
{
    std::ifstream in("SAVEFILE.dta");
    player.readFromFile(in);
}


void adventure(int act)
{
    char ch[STRLEN] = "";
    if (act == 1)
    {
        std::cout
        << "Welcome to the realm of Eshance, " << player.getName() << " of the " << player.getRace() << "s.\n"
        << "More specifically, welcome to the kingdom of Ishlance\n\n"
        << "As an outlaw escaping from a southern kingdom, it is up "
        << "to you to survive in these harsh, wintery lands.\n"
        << "Hopefully you are trained in the necessary skills to ensure your survival...\n\n";
        waitForInput();

        std::cout
        << "\nAfter losing your horse in the night, you finally stumble upon a village.\n\n"
        << "You have been noticed by a guard on night shift. What do you want to do?\n"
        << "\t'Approach' the guard.\n\t'Attack' the guard.\n\t'Leave' and run back into the forest.\n";
    }
    
    readCharArray("Command", ch, STRLEN);
    
    while(ch != "APPROACH" && ch != "ATTACK" && ch != "LEAVE")
    {
        std::cout
        << "So you really didn´t understand that the valid inputs were marked like 'this'?\n"
        << "Or did you look for secret commands? Either way, good luck...\n";
        strcpy(ch,""); readCharArray("Command", ch, STRLEN);
    }
    
    if (!strcmp(ch,"ATTACK"))
    {
        std::cout
        << "You start charging the guard. Get ready for battle!\n";
        player.battle(Guard);
    }
    else if(!strcmp(ch,"APPROACH"))
    {
        approachGuard(1);
    }
    else if(!strcmp(ch,"LEAVE"))
    {
        forest("RUN", "VILLAGE", 1);
    }
}


void approachGuard(int act)
{
    char c[STRLEN];
    readCharArray("Command", c, STRLEN);
    
    std::cout
    << "You approach the guard. He stares at you suspiciously.\n"
    << "\t'What´s your purpose here, " << player.getRace() << "?'\n"
    << "\n- Ask for 'directions'.\n"
    << "- Ask if he knows of any available 'work'.\n"
    << "- Tell a 'joke'. (He might not like it..)\n";
    readCharArray("Command", c, STRLEN);

    while(c != "JOKE" && c != "DIRECTIONS" &&
          c != "WORK" && c != "BRIBE"){
        strcpy(c," "); readCharArray("Command", c, STRLEN);
    }

    if (!strcmp(c,"DIRECTIONS"))
    {
        
    }
    else if (!strcmp(c,"WORK"))
    {

    }
    else if (!strcmp(c,"JOKE") || !strcmp(c,"TELL JOKE"))
    {

    }
    //    if (approachInput == "joke"){
    //        if (posSkills[3] >= 5){
    //            PrintSpace();
    //            cout << "The guard liked the joke, and he releases the grip of his spear." << endl;
    //            cout << "\t'What can I help you with, " << raceInput << "?'";
    //        }
    //        else{
    //            cout << "The guard did not find it funny. He readies his spear." << endl;
    //        }
    //    }
    //    else if (approachInput == "work"){
    //        PrintSpace();
    //        cout << "The guard scans you up and down." << endl;
    //
    //        if (posSkills[0] >= 6){
    //            cout << "\t'You look like you could swing a sword.\n\t Seek out the commander ";
    //            cout << "if you´re\n\t interested in some.. heavier.. work.'" << endl;
    //            commanderQuest = true;
    //            numberOfQuests++;
    //            PrintQuestObtained();
    //            }
    //
    //        else{
    //            PrintSpace();
    //            cout << "\t'You might have some luck in the tavern. Look for the innkeeper.'"<< endl;
    //        }
    //
    //    }
    //
    //    PrintLine();
    //    cout << "The guard will let you enter the village." << endl;
    //    cout << "\n\t'enter' the village.\n\tReturn to the 'forest'" << endl;
    //    do{
    //        cout << "Command: "; cin >> leaveInput;
    //    }while(leaveInput!= "enter" && leaveInput!= "forest" && leaveInput != "sneak");
    //
    //    if (leaveInput=="forest"){
    //        Forest();
    //    }
    //    else if (leaveInput=="enter"){
    //        VillageOne();
    //    }
    //    else if (leaveInput=="sneak"){
    //        cout << "You thank the guard and walk out of his sight./nYou wait behing a tree until dark,";
    //        cout << " then sneak back to the wall. Why? Because you can." << endl;
    //        cout << "You climb the wall, and drop down inside the village without a sound. Time to steal." << endl;
    //        villageSneak=true;
    //        VillageOne();
    //    }
    //}
}


void forest(char* why, char* from, int act){

    char ch[INLEN] = " ";
    char* options[] = { "LOOK", "CAMP", "RUN", "HUNT" };
    char forestName[STRLEN];
    
    if (!strcmp(from, "VILLAGE") && !(strcmp(why, "RUN")))
    {
        std::cout
        << "You run away from the village in a random direction.\n"
        << "Good job, now you´ve done it... There are only trees to be seen in every direction.\n"
        << "What are you gonna do out here?\n";
    }
    else if (!strcmp(from, "VILLAGE") && !(strcmp(why, "TRAVEL")))
    {
        std::cout
        << "You leave the village to continue the journey.\n"
        << "What are you gonna do out here?\n";
    }
    else if (!strcmp(from, "CASTLE") && !strcmp(why, "QUEST"))
    {
        std::cout
        << "You leave the castle to embark on your new quest.\n"
        << "What are you gonna do out here?\n";
    }
             
    std::cout
    << "\n\t'Look' for food.\n\t'Hunt' for food.\n\tKeep 'Moving' the same direction."
    << "\n\tMake a 'Camp' for the night.";
    readCharArray("Command", ch, STRLEN);
    do{
        std::cout
        << "Let´s try using a valid input.\n";
        strcpy(ch,""); readCharArray("Command", ch, STRLEN);
    } while (ch != options[0] && ch != options[1] && ch != options[2] && ch != options[3]);

    switch (act)
    {
        case 1:
            std::cout << "You have entered the huge forest situated in the Frostpine Valley.\n";
            strcpy(forestName,"Frostpine Valley"); break;
        case 2:
            std::cout << "You have entered the Blindweir Woods, watch out for eye-poking branches...\n";
            strcpy(forestName,"Blindweir Woods"); break;
        case 3:
            std::cout << "You just entered the un-named forest.\nGood luck...\n\n";
            strcpy(forestName,"an un-named forest"); break;
        default: break;
    }
    
    if (!strcmp(ch, "LOOK"))
    {
        std::cout
        << "Good choice, you go out and look for food.\n"
        << "Let´s hope the cold haven´t driven all the animals south already.\n";
        if (player.getSkillValue(Luck) >= 5){
            std::cout
            << "You´re lucky! You find a nest of Veircrow eggs, and manage to trap a rabbit as well.\n"
            << "This will be enough for the night and maybe even the next day.\n";
//            player.addFood(VEIRCROWEGGS+RABBIT);
        }
        else{
            std::cout
            << "You find some roots and manage to trap a small rabbit. It´s not much, but it´ll do for today.\n";
//            player.addFood(ROOTS+RABBITSMALL);
        }
    }
    else if (!strcmp(ch, "CHOP"))
    {
        std::cout
        << "You start chopping down trees, one after another. But you don´t have an axe... How?\n"
        << "Now that´s a workout.\nOr are you actually a giant?\n"
        << "*** You gained 1 STRENGTH ***\n";
        player.increaseSkill(Strength, 1);
    }
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




