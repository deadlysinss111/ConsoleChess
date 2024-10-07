#pragma once

class Pawn : public Piece
{
public:
	Pawn(COLOR color, Cell* pos);
	~Pawn();

	bool CheckDest(Cell*) override;

private:
	
};

