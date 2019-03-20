#ifndef __HELPFUNCTIONS_H
#define __HELPFUNCTIONS_H

#include <fstream>

char command();
void readCharArray(char txt[], char c[], int max);  // Returns uppercased input
void readName(char txt[], char c[], int max);       // No uppercased input
void uppercaseString(char c[]);
int readInt(char txt[], int min, int max);
void setDifficulty(int d);
int readNumber(char txt[], int min, int max);
void readPointerFromFile(std::ifstream &inn, char* & t);
void spacing(int n);
void waitForInput();
void writeChoices(int n, char* c[]);

#endif
