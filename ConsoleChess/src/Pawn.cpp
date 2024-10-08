#include "pch.h"

Pawn::Pawn(COLOR color, Cell* cell) : Piece(color, cell) {	
	_symbol = 'p';
}

Pawn::~Pawn() {

}

void Pawn::SetAccesibleCellsToPlayable(Board* board) {
	int offset = _color == WHITE ? -1 : 1;

	// check for forward cell first
	Cell* target = board->GetCellAt(_posCell->pos.x, _posCell->pos.y + offset);

	if (target == nullptr) return;

	if (target->occupedBy == nullptr)
		target->playable = true;

	// the two ones in diagonale then
	target = board->GetCellAt(_posCell->pos.x +1 , _posCell->pos.y + offset);
	if (target != nullptr) {
		if (target->occupedBy != nullptr)
			if (target->occupedBy->_color != _color)
				target->playable = true;
	}

	target = board->GetCellAt(_posCell->pos.x -1 , _posCell->pos.y + offset);
	if (target != nullptr) {
		if (target->occupedBy != nullptr)
			if (target->occupedBy->_color != _color)
				target->playable = true;
	}
}