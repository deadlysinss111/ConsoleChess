#pragma once

class Piece
{
public:
	Piece(COLOR color, Cell* pos);
	~Piece();
	//virtual ~Piece();

public:
	void MoveTo(Cell*);
	//void MoveTo(int x, int y) {};
	virtual void SetAccesibleCellsToPlayable(Board*) = 0;
	virtual void OnDeath(Board*) {};

public:
	COLOR _color;
	char _symbol;
	Cell* _posCell;
};

