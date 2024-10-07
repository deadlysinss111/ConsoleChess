#include "pch.h"

Rook::Rook(COLOR color, Cell* cell) : Piece(color, cell) {
	_symbol = 'r';
	_legalMoves = { Position(0, 1) };
}

Rook::~Rook() {

}
void Rook::SetAccesibleCellsToPlayable(Board* board) {
	//lets go up first
	int offset = 1;
	Cell* target = board->GetCellAt(_posCell->pos.x, _posCell->pos.y - offset);
	while(target != nullptr){
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			break;
		}

		++offset;
		Cell* target = board->GetCellAt(_posCell->pos.x, _posCell->pos.y + offset);
	}

	// down
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
	while (target != nullptr) {
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			break;
		}

		++offset;
		Cell* target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
	}

	// right
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
	while (target != nullptr) {
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			break;
		}

		++offset;
		Cell* target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
	}

	// left
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x - offset, _posCell->pos.y);
	while (target != nullptr) {
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			break;
		}

		++offset;
		Cell* target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
	}
}