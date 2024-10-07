#include "pch.h"

Piece::Piece(COLOR color, Cell* cell) {
	_color = color;
	_posCell = cell;
}

Piece::~Piece() {
	
}

void Piece::MoveTo(Cell* dest) {
	dest->occupedBy = this;
	_posCell->occupedBy = nullptr;
	_posCell = dest;
}

void Piece::SetAccesibleCellsToPlayable(Board* board) {
	for (Position pos : _legalMoves) {
		Cell* target = board->GetCellAt(_posCell->pos.x + pos.x, _posCell->pos.y + pos.y);
		if (target->occupedBy == nullptr)
			target->playable = true;
		else if(target->occupedBy->_color != _color)
			target->playable = true;
	}
}