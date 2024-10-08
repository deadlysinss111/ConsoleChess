#pragma once

class Knight : public Piece
{
public:
	Knight(COLOR color, Cell* pos);
	~Knight();

public:
	void SetAccesibleCellsToPlayable(Board*) override;

private:
	void InternalBehaviour(Cell* target);
};

