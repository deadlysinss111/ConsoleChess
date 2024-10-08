#pragma once

class Pawn : public Piece
{
public:
	Pawn(COLOR color, Cell* pos);
	~Pawn();

	void SetAccesibleCellsToPlayable(Board*) override;

private:
	
};

