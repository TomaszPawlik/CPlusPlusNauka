#include "Board.h"
#include <iostream>
#include <string>

using namespace std;

Board::Board(const int boardWidth, const int boardHeight)
{
	width = boardWidth;
	height = boardHeight;

	cellBoard = new Cell**[boardHeight];

	for (int i = 0; i < boardHeight; i++)
		cellBoard[i] = new Cell*[boardWidth];

	for (int i = 0; i < boardHeight; i++)
		for (int j = 0; j < boardWidth; j++)
			cellBoard[i][j] = new Cell();
}

Board::~Board()
{
    for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++){
			delete cellBoard[i][j];
        }
    for (int i = 0; i < height; i++)
        delete cellBoard[i];

    delete cellBoard;
}

void Board::setDangerZones(int x, int y){
    if ((x>0 && x<this->height-1)&&(y>0 && y<this->width-1)){
        for (int i=x-1;i<x+2;i++)
            for (int j=y-1;j<y+2;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x==0)&&(y==0)){
        for (int i=0;i<2;i++)
            for (int j=0;j<2;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x==this->height-1)&&(y==this->width-1)){
        for (int i=x-1;i<x+1;i++)
            for (int j=y-1;j<y+1;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x==this->height-1)&&(y==0)){
        for (int i=x-1;i<x+1;i++)
            for (int j=0;j<2;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x==0)&&(y==this->width-1)){
        for (int i=0;i<2;i++)
            for (int j=y-1;j<y+1;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x>0 && x<this->height-1)&&(y==0)){
        for (int i=x-1;i<x+2;i++)
            for (int j=0;j<2;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x>0 && x<this->height-1)&&(y==this->width-1)){
        for (int i=x-1;i<x+2;i++)
            for (int j=y-1;j<y+1;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x==0)&&(y>0 && y<this->width-1)){
        for (int i=0;i<2;i++)
            for (int j=y-1;j<y+2;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    } else if ((x==this->height-1)&&(y>0 && y<this->width-1)){
        for (int i=x-1;i<x+1;i++)
            for (int j=y-1;j<y+2;j++){
                if (cellBoard[i][j]->getState()==state::empty)
                    cellBoard[i][j]->setAsDanger();
                cellBoard[i][j]->incDangerLevel();
        }
    }
}

void Board::setCellAsMine(int x, int y)
{
	cellBoard[x][y]->setAsMine();
	setDangerZones(x,y);
}

void Board::setMinesOnBoard(int number)
{
	int x, y;
	do {
		x = rand() % height;
		y = rand() % width;

		if (cellBoard[x][y]->getState() != state::mine) {
			setCellAsMine(x, y);
			number--;
		}
	} while (number > 0);
}

void Board::printBoard() {
	for (int i = 0; i < this->height; i++) {
		for (int j = 0; j < this->width; j++){
			if (cellBoard[i][j]->getState() == state::empty)
				cout << "[ ] ";
			else if (cellBoard[i][j]->getState() == state::mine)
				cout << "[M] ";
            else if (cellBoard[i][j]->getState() == state::danger)
                cout << "[" << cellBoard[i][j]->getDangerLevel() << "] ";
		}
		cout << "\n";
	}
}
