#include "Cell.h"
#include "Board.h"
#include <time.h>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(NULL));
	int width = 10, height = 8;

	Board * b1 = new Board(width, height);

	b1->setMinesOnBoard(20);
	b1->printBoard();

	delete b1;
}
