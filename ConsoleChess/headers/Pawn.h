#pragma once

class Pawn : public Piece
{
public:
	Pawn(COLOR color, Cell* pos);
	~Pawn();

public:
	void SetAccesibleCellsToPlayable(Board*) override;

private:
	bool _didMove;

};

