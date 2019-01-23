#pragma once

enum state {
	empty, danger, mine
};

class Cell
{

	int dangerLevel=0;
	state cellState;
	friend class Board;

	Cell();
	~Cell();

	void setAsMine();
	void setAsDanger();
	state getState();
	void incDangerLevel();
	int getDangerLevel();
};
