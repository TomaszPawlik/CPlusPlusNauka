#include "MainMenu.h"

MainMenu::MainMenu()
{
    //ctor
}

MainMenu::~MainMenu()
{
    //dtor
}

bool MainMenu::getQuit(){
    return quit;
}

int MainMenu::getChoiceFromUser(int numberOfOptions)
{
    int choice;

    do
    {
        cout << "Your choice: ";
        cin >> choice;
        if (choice<0 || choice>numberOfOptions-1)
            cout << "Invalid output .... Please repeat." << endl;
    }
    while (choice<0 || choice>numberOfOptions-1);

    return choice;
}

RPGCharacter* MainMenu::createNewCharacter(int choice)
{
    RPGCharacter* newChar = new RPGCharacter(choice);

    system("CLS");

    cout << "Enter Your character name: ";
    cin >> newChar->name;

    return newChar;
}

void MainMenu::showChooseCharacterOption()
{

    cout << "Select character: " << endl
         << "(1) Warrior" << endl
         << "(2) Rogue" << endl
         << "(3) Mage" << endl
         << "(0) Back to: Main Menu" << endl;

    switch (getChoiceFromUser(4) | system("CLS"))
    {
    case 1:
        showDifficultyOption(createNewCharacter(1));
        break;
    case 2:
        showDifficultyOption(createNewCharacter(2));
        break;
    case 3:
        showDifficultyOption(createNewCharacter(3));
        break;
    case 0:
        showMainMenu();
        break;
    }
}

void MainMenu::startGame(RPGCharacter * RPGchar, difficulty dif)
{
    system("CLS");
    cout << "Loading new game..." << endl
         << "Your character name: " << RPGchar->name << endl
         << "Difficulty level: " << displayDifficulty(dif) << endl;
    Sleep(2000);
    delete RPGchar;
}

void MainMenu::showDifficultyOption(RPGCharacter * RPGchar)
{
    cout << "Select difficulty: " << endl
         << "(1) Easy" << endl
         << "(2) Normal" << endl
         << "(3) Hard" << endl
         << "(0) Back to: Select character" << endl;

    switch (getChoiceFromUser(4) | system("CLS"))
    {
    case 1:
        startGame(RPGchar, difficulty::easy);
        break;
    case 2:
        startGame(RPGchar, difficulty::normal);
        break;
    case 3:
        startGame(RPGchar, difficulty::hard);
        break;
    case 0:
        delete RPGchar;
        showChooseCharacterOption();
        break;
    }
}

void MainMenu::showLoadGameOption()
{

    cout << "Load game: " << endl
         << "(1) Slot 1" << endl
         << "(2) Slot 2" << endl
         << "(3) Slot 3" << endl
         << "(4) Slot 4" << endl
         << "(0) Back to: Main Menu" << endl;

    switch (getChoiceFromUser(5) | system("CLS"))
    {
    case 1:
        cout << "Loading game slot 1 ..." << endl;
        system("PAUSE");
        break;
    case 2:
        cout << "Loading game slot 2 ..." << endl;
        system("PAUSE");
        break;
    case 3:
        cout << "Loading game slot 3 ..." << endl;
        system("PAUSE");
        break;
    case 4:
        cout << "Loading game slot 4 ..." << endl;
        system("PAUSE");
        break;
    case 0:
        showMainMenu();
        break;
    }
}

void MainMenu::showCreditsOption()
{

    cout << "Credits: " << endl
         << "Tomasz Pawlik" << endl
         << "Press any key to continue: " << endl;
    system("PAUSE");
    showMainMenu();
}

void MainMenu::showMainMenu()
{
    system("CLS");
    cout << "+++ Game Menu Logic +++" << endl
         << "+++ +++++++++++++++ +++" << endl
         << "(1) New Game" << endl
         << "(2) Load Game" << endl
         << "(3) Credits" << endl
         << "(0) Quit" << endl;

    switch (getChoiceFromUser(4) | system("CLS"))
    {
    case 1:
        showChooseCharacterOption();
        break;
    case 2:
        showLoadGameOption();
        break;
    case 3:
        showCreditsOption();
        break;
    case 0:
        cout << "Unit next time!";
        quit=true;
        break;
    }
}

string MainMenu::displayDifficulty (difficulty dif)
{
    string returnValue;
    if (dif==0)
        returnValue="Easy";
    else if (dif==1)
        returnValue="Normal";
    else
        returnValue="Hard";
    return returnValue;
}
