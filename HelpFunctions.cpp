
#include "HelpFunctions.h"
#include "Const.h"

#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;


char command()
{
    char c; std::cout << "Command: "; std::cin >> c; std::cin.ignore(); return (toupper(c));
}


void readCharArray(char txt[], char c[], int max)
{
    while (strlen(c) < 1 || strlen(c) > max)
    {
        std::cout << txt << ": "; std::cin.getline(c, max);
    }
    uppercaseString(c);
}


void readName(char txt[], char c[], int max)
{
    while (strlen(c) < 1 || strlen(c) > max)
    {
        std::cout << txt << ": "; std::cin.getline(c, max);
    }
}


void uppercaseString(char c[])
{
    for (int i = 0; i < (int)strlen(c); i++) {
        c[i] = toupper(c[i]);
    }
}


int readInt(char txt[], int min, int max)
{
    int i = 0;
    while (i < min || i > max)
    {
        std::cout << "Command (" << min << " - " << max << "): "; std::cin >> i;
        
        if (i < min || i > max)
        {
            std::cout << "\nTry entering a valid number...!\n";
        }
    }
    return i;
}


int readNumber(char txt[], int min, int max)
{
    int i = 0;
    while (i < min || i > max)
    {
        std::cout << txt; std::cin >> i;
        
        if (i < min || i > max)
        {
            std::cout << "\nTry entering a valid number...!\n";
        }
    }
    return i;
}


void readPointerFromFile(ifstream &inn, char* & t)
{
    char temp[STRLEN];
    inn.getline(temp, STRLEN);
    t = new char[strlen(temp) + 1]; strcpy(t, temp);
}


void spacing(int n)
{
    for (int i = 0; i < n; i++) { std::cout << "\n"; }
}


void waitForInput()
{
    char c[INLEN];
    std::cout << "->"; std::cin.getline(c, INLEN);
}


void writeChoices(int n, char* c[])
{
    for (int i = 0; i < n; i++) {
        std::cout << c[i] << "\n";
    }
}




