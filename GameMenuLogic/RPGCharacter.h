#include <string>

using namespace std;

class RPGCharacter
{

public:
    string name, race, charClass;
    int str, dex, vit, ing, wis, cha;

    RPGCharacter(int choice);
    ~RPGCharacter();
};
