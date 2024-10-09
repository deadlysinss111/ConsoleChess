#pragma once

class Board
{
public:
	Board();
	~Board();
	void Init();

public:
	Cell* _board;
	bool _gameOver;

public:
	Cell* GetCellAt(int x, int y);
	bool MoveFromTo(int baseX, int baseY, int destX, int destY);
	bool MoveFromTo(Cell* base, Cell* dest);

public:
	void Display(HANDLE* hConsole);
	void ResetColor();
	void ResetPlayableCells();

private:
	char GetSymbolAt(int x, int y);
};

