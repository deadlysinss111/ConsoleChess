#pragma once

class Piece
{
public:
	Piece(COLOR color, Cell* pos);
	~Piece();
	//virtual ~Piece();

protected:
	std::vector<Position> _legalMoves;

public:
	void MoveTo(Cell*);
	void MoveTo(int x, int y) {};
	virtual bool CheckDest(Cell*) { return false; };
	//virtual bool CheckDest(int x, int y) = 0;
	virtual void SetAccesibleCellsToPlayable(Board*);

public:
	COLOR _color;
	char _symbol;
	Cell* _posCell;
};

