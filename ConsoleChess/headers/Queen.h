#pragma once

class Queen : public Piece
{
public:
	Queen(COLOR color, Cell* pos);
	~Queen();

public:
	void SetAccesibleCellsToPlayable(Board*) override;
};

