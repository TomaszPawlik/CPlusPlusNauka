#include "Cell.h"

Cell::Cell() {
	cellState = state::empty;
}

Cell::~Cell() {
}

void Cell::setAsMine() {
	cellState = state::mine;
}

void Cell::setAsDanger() {
	cellState = state::danger;
}

state Cell::getState() {
	return cellState;
}

void Cell::incDangerLevel(){
    this->dangerLevel++;
}

int Cell::getDangerLevel(){
    return this->dangerLevel;
}
