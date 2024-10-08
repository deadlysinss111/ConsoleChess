#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
	Bishop(COLOR color, Cell* pos);
	~Bishop();

public:
	void SetAccesibleCellsToPlayable(Board*) override;
};

