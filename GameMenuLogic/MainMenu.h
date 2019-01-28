#include <iostream>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <Windows.h>

#include <RPGCharacter.h>
#include <difficultyEnum.h>

class MainMenu
{
    public:
        MainMenu();
        ~MainMenu();

        bool getQuit();
        void showMainMenu();

    protected:

    private:

        bool quit = false;

        int getChoiceFromUser(int numberOfOptions);
        RPGCharacter* createNewCharacter(int choice);
        void showChooseCharacterOption();
        void startGame(RPGCharacter * RPGchar, difficulty dif);
        void showDifficultyOption(RPGCharacter * RPGchar);
        void showLoadGameOption();
        void showCreditsOption();

        string displayDifficulty (difficulty dif);
};
