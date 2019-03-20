#ifndef __QUEST_H
#define __QUEST_H

#include "ListTool2B.h"
#include "Const.h"


class Quest : public TextElement
{
private:
    char* contact;
    char reward[STRLEN];
    int experience;
    
public:
    Quest(char* n, char c[], char r[], int e);
    void questInfo();
};

#endif
