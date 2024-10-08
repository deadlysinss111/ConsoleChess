#include "pch.h"

Queen::Queen(COLOR color, Cell* cell) : Piece(color, cell) {
	_symbol = 'q';
}

Queen::~Queen() {

}
void Queen::SetAccesibleCellsToPlayable(Board* board) {
	// let first go for the + form
	
	//lets go up first
	int offset = 1;
	Cell* target = board->GetCellAt(_posCell->pos.x, _posCell->pos.y - offset);
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
			target = board->GetCellAt(_posCell->pos.x, _posCell->pos.y + offset);
		}
	}

	// down
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x, _posCell->pos.y + offset);
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
			target = board->GetCellAt(_posCell->pos.x, _posCell->pos.y + offset);
		}
	}

	// right
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y);
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

	// left
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x - offset, _posCell->pos.y);
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

	// we now go for the X form

	//lets go up right first
	offset = 1;
	target = board->GetCellAt(_posCell->pos.x + offset, _posCell->pos.y - offset);
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