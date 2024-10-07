#include "pch.h"

Pawn::Pawn(COLOR color, Cell* cell) : Piece(color, cell) {
	switch (color) {
	case WHITE:
		_legalMoves = { Position(0, -1) };
		break;
	case BLACK:
		_legalMoves = { Position(0, 1) };
		break;
	}
	
	_symbol = 'p';
}

Pawn::~Pawn() {

}

bool Pawn::CheckDest(Cell* target) {
	/*Position operand;
	operand = target->pos - _posCell->pos;
	for (Position legal : _legalMoves) {
		if (legal == operand) {
			return true;
		}
	}
	return false;*/
	return true;
}