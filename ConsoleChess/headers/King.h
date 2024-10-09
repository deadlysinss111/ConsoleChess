#pragma once

class King : public Piece
{
public:
	King(COLOR color, Cell* pos);
	~King();

public:
	void SetAccesibleCellsToPlayable(Board*) override;
	void OnDeath(Board*) override;

};

