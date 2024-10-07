#pragma once

class Rook : public Piece
{
public:
	Rook(COLOR color, Cell* cell);
	~Rook();

public:
	void SetAccesibleCellsToPlayable(Board*) override;
};