#include "pch.h"


Cell::Cell(Position basePos) {
	pos = basePos;
	occupedBy = nullptr;
	playable = false;
	color = 15;
}

Cell::Cell() {
	pos = Position();
	occupedBy = nullptr;
	playable = false;
	color = 15;
}