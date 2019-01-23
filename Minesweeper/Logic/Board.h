#include "Cell.h"

class Board
{
	int width, height;
	Cell *** cellBoard;

    void setDangerZones(int x, int y);

public:

	Board(int boardWidth, int boardHeight);
    ~Board();

	void setCellAsMine(int x, int y);
	void setMinesOnBoard(int number);
	void printBoard();
};

