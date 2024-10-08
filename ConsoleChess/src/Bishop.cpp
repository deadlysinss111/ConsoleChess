#include "pch.h"

Bishop::Bishop(COLOR color, Cell* cell) : Piece(color, cell) {
	_symbol = 'b';
}

Bishop::~Bishop() {

}
void Bishop::SetAccesibleCellsToPlayable(Board* board) {
	//lets go up right first
	int offset = 1;
	Cell* target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y - offset);
	while (target != nullptr) {
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			target = nullptr;
		}
		else {
			target->playable = true;
			++offset;
			target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y - offset);
		}
	}

	// up left
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x - offset, _posCell->pos.y - offset);
	while (target != nullptr) {
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			target = nullptr;
		}
		else {
			target->playable = true;
			++offset;
			target = board->GetCellAt(_posCell->pos.x - offset, _posCell->pos.y - offset);
		}
	}

	// down right
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y + offset);
	while (target != nullptr) {
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			target = nullptr;
		}
		else {
			target->playable = true;
			++offset;
			target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
		}
	}

	// down left
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x - offset, _posCell->pos.y + offset);
	while (target != nullptr) {
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color) {
				target->playable = true;
			}
			target = nullptr;
		}
		else {
			target->playable = true;
			++offset;
			target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
		}
	}
}