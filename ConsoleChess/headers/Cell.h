#pragma once

struct Cell {
	Position pos;
	Piece* occupedBy;
	int color;
	bool playable;

	Cell(Position);
	Cell();
};