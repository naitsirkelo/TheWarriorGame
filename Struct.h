#ifndef __STRUCT_H
#define __STRUCT_H

#include "Const.h"

#include <string>


struct Quest
{
    std::string contact;
    std::string objective;
    std::string reward;
    int experience;
} begin, end;

#endif
