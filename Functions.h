#ifndef __FUNCTIONS_H
#define __FUNCTIONS_H

#include <fstream>

void title();
void welcomeScreen();
void menuPlayerNotCreated();
void menuPlayerCreated();
void menuStartedAdventure();
void writeLore();
void saveGame();
void loadGame();
void adventure(int act);
void approachGuard(int act);
void forest(char* why, char* from, int act);
void battleCommands();

#endif
