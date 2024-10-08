#include "pch.h"

Knight::Knight(COLOR color, Cell* cell) : Piece(color, cell) {
	_symbol = 'k';
}

Knight::~Knight() {

}
void Knight::SetAccesibleCellsToPlayable(Board* board) {

	//lets go up right first
	Cell* target = board->GetCellAt(_posCell->pos.x + 1, _posCell->pos.y - 2);

	InternalBehaviour(target);			

	target = board->GetCellAt(_posCell->pos.x + 2, _posCell->pos.y - 1);

	InternalBehaviour(target);

	// up left
	target = board->GetCellAt(_posCell->pos.x - 1, _posCell->pos.y - 2);

	InternalBehaviour(target);

	target = board->GetCellAt(_posCell->pos.x - 2, _posCell->pos.y - 1);

	InternalBehaviour(target);

	// down right
	target = board->GetCellAt(_posCell->pos.x + 1, _posCell->pos.y + 2);

	InternalBehaviour(target);

	target = board->GetCellAt(_posCell->pos.x + 2, _posCell->pos.y + 1);

	InternalBehaviour(target);

	// down left
	target = board->GetCellAt(_posCell->pos.x - 1, _posCell->pos.y - 2);

	InternalBehaviour(target);

	target = board->GetCellAt(_posCell->pos.x - 2, _posCell->pos.y - 1);

	InternalBehaviour(target);
}

void Knight::InternalBehaviour(Cell* target) {
	if (target != nullptr)
		if (target->occupedBy != nullptr) {
			if (target->occupedBy->_color != _color)
				target->playable = true;
		}
		else {
			target->playable = true;
		}
}