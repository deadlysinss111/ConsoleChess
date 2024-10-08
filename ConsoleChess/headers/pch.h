#pragma once

#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <Windows.h>
#include <conio.h>

#ifdef _DEBUG
	#include <crtdbg.h>
#endif

#ifdef _DEBUG
	#define DEBUG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
	#define new DEBUG_NEW
#endif


#ifdef _LOG
	#define LOG(str)		{HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole, WHITE); std::cout << str << std::endl;}
#else
	#define LOG(str)
#endif


#define COLOR bool
#define WHITE false
#define BLACK true

// board colors
#define C_BLACK 12
#define C_WHITE 15
#define C_EMPTY 8
#define C_PLAYABLE 11

// input macro
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define CONFIRM 32

struct Position;
struct Cell;

class Board;
class Piece;
class Pawn;
class Rook;
class Bishop;
class Knigth;
class Queen;
class King;


#include "Position.h"
#include "Cell.h"

#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"