
#include "ListTool2B.h"
#include "Quest.h"

#include <iostream>
#include <string>


Quest::Quest(char* n, char c[], char r[], int e) : TextElement(n)
{
    contact = new char[strlen(c) + 1]; strcpy(contact, c);
    strcpy(reward, r);
    experience = e;
}


void Quest::questInfo()
{
    std::cout
    << text << "\n\n";
    
    if (contact)
    {
        std::cout << contact << "\n";
    }
    std::cout
    << reward << "\tXP: " << experience << "\n\n";
}




