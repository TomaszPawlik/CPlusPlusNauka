#include "RPGCharacter.h"
//#include <iostream>
//#include <string>
using namespace std;

RPGCharacter::RPGCharacter(int choice)
{
    switch (choice)
    {
    case 1:
        this->name = "WarriorName";
        this->charClass = "Warrior";
        this->race = "Human";
        this->str = 16;
        this->dex = 12;
        this->vit = 14;
        this->ing = 10;
        this->wis = 10;
        this->cha = 10;
        break;
    case 2:
        this->name = "RogueName";
        this->charClass = "Rogue";
        this->race = "Human";
        this->str = 8;
        this->dex = 16;
        this->vit = 8;
        this->ing = 12;
        this->wis = 14;
        this->cha = 14;
        break;
    case 3:
        this->name = "MageName";
        this->charClass = "Mage";
        this->race = "Elf";
        this->str = 8;
        this->dex = 10;
        this->vit = 8;
        this->ing = 18;
        this->wis = 16;
        this->cha = 12;
        break;
    }
}

RPGCharacter::~RPGCharacter()
{
//        cout << "Deleting RPGCharacter Object ... " << this->name << endl;
//        system("PAUSE");
}
