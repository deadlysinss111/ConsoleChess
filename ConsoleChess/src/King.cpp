#include "pch.h"

King::King(COLOR color, Cell* cell) : Piece(color, cell) {
	_symbol = 'K';
}

King::~King() {

}

void King::SetAccesibleCellsToPlayable(Board* board) {
	Cell* target;

	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++) {
			target = board->GetCellAt(_posCell->pos.x + i, _posCell->pos.y + j);
			if (target == nullptr) continue;

			if (target->occupedBy != nullptr) {
				if (target->occupedBy->_color != _color)
					target->playable = true;
			}
			else {
				target->playable = true;
			}
		}
	}
}

void King::OnDeath(Board* board) {
	board->_gameOver = true;
}