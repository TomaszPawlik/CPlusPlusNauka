#include <MainMenu.h>

using namespace std;

int main()
{
    MainMenu mm;
    while (!mm.getQuit())
    {
        mm.showMainMenu();
    }

    return 0;
}


