#ifndef __CLAN_H
#define __CLAN_H

#include <fstream>


class Clan
{
private:
    char* name;
public:
    Clan(std::ifstream &inn, char* n);
    void clanInfo();
    char* getName() { return name; }
};

#endif
