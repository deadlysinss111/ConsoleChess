#include "pch.h"

Board::Board() {
	_board = new Cell[64];
	_gameOver = false;
	Init();
}

Board::~Board() {
	delete _board;
}

void Board::Init() {
#ifdef _LITE
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Cell cell(Position(i, j));

			// Dispose pieces
			switch (j) {
			case 0:
				cell.occupedBy = new Pawn(BLACK, &(_board[i + 8 * j]));
				break;
			case 1:
				cell.occupedBy = new Pawn(BLACK, &(_board[i + 8 * j]));
				break;
			case 6:
				cell.occupedBy = new Pawn(WHITE, &(_board[i + 8 * j]));
				break;
			case 7:
				cell.occupedBy = new Pawn(WHITE, &(_board[i + 8 * j]));
				break;
			default:
				break;
			}
			_board[i + 8 * j] = cell;

		}
}
#else
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Cell cell(Position(i, j));

			// Dispose pieces
			switch (j) {
			case 0:
				switch (i) {
				case 0:
					cell.occupedBy = new Rook(BLACK, &(_board[i + 8 * j]));
					break;
				case 1:
					cell.occupedBy = new Knight(BLACK, &(_board[i + 8 * j]));
					break;
				case 2:
					cell.occupedBy = new Bishop(BLACK, &(_board[i + 8 * j]));
					break;
				case 3:
					cell.occupedBy = new King(BLACK, &(_board[i + 8 * j]));
					break;
				case 4:
					cell.occupedBy = new Queen(BLACK, &(_board[i + 8 * j]));
					break;
				case 5:
					cell.occupedBy = new Bishop(BLACK, &(_board[i + 8 * j]));
					break;
				case 6:
					cell.occupedBy = new Knight(BLACK, &(_board[i + 8 * j]));
					break;
				case 7:
					cell.occupedBy = new Rook(BLACK, &(_board[i + 8 * j]));
					break;
				}
				break;
			case 1:
				cell.occupedBy = new Pawn(BLACK, &(_board[i + 8 * j]));
				break;
			case 6:
				cell.occupedBy = new Pawn(WHITE, &(_board[i + 8 * j]));
				break;
			case 7:
				switch (i) {
				case 0:
					cell.occupedBy = new Rook(WHITE, &(_board[i + 8 * j]));
					break;
				case 1:
					cell.occupedBy = new Knight(WHITE, &(_board[i + 8 * j]));
					break;
				case 2:
					cell.occupedBy = new Bishop(WHITE, &(_board[i + 8 * j]));
					break;
				case 3:
					cell.occupedBy = new King(WHITE, &(_board[i + 8 * j]));
					break;
				case 4:
					cell.occupedBy = new Queen(WHITE, &(_board[i + 8 * j]));
					break;
				case 5:
					cell.occupedBy = new Bishop(WHITE, &(_board[i + 8 * j]));
					break;
				case 6:
					cell.occupedBy = new Knight(WHITE, &(_board[i + 8 * j]));
					break;
				case 7:
					cell.occupedBy = new Rook(WHITE, &(_board[i + 8 * j]));
					break;
				}
				break;
			default:
				break;
			}
			_board[ i + 8 * j] = cell;

		}
	}
#endif

	ResetColor();
}

Cell* Board::GetCellAt(int x, int y) {
	if (x < 0 || x > 7 || y < 0 || y > 7) return nullptr;

	return &(_board[x + 8 * y]);
}

bool Board::MoveFromTo(int baseX, int baseY, int destX, int destY) {
	Cell* base = GetCellAt(baseX, baseY);
	Cell* dest = GetCellAt(destX, destY);

	return MoveFromTo(base, dest);
}

bool Board::MoveFromTo(Cell* base, Cell* dest) {
	if (base->occupedBy == nullptr) return false;

	if (dest->occupedBy != nullptr) {
		dest->occupedBy->OnDeath(this);
	}

	base->occupedBy->MoveTo(dest);
	return true;
}

void Board::Display(HANDLE* hConsole) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			Cell* cell = GetCellAt(j, i);
			SetConsoleTextAttribute(*hConsole, cell->color);
			std::cout << ' ' << GetSymbolAt(j, i);
		}
		std::cout << std::endl;
	}
}

void Board::ResetColor() {
	for (int i = 0; i < 64; i++) {
		if (_board[i].playable) {
			_board[i].color = C_PLAYABLE;
		}
		else if (_board[i].occupedBy == nullptr) {
			_board[i].color = C_EMPTY;
		}
		else if (_board[i].occupedBy->_color == BLACK) {
			_board[i].color = C_BLACK;
		}
		else {
			_board[i].color = 15;
		}
	}
}

void Board::ResetPlayableCells() {
	for (int i = 0; i < 64; i++) {
		_board[i].playable = false;
	}
}

char Board::GetSymbolAt(int x, int y) {
	Piece* target = (_board[x + 8 * y]).occupedBy;
	if (target != nullptr) {
		return target->_symbol;
	}
	return '0';
}