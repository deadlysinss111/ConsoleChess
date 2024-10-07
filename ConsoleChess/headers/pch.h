#pragma once

#include <iostream>
#include <stdio.h>
#include <utility>
#include <vector>
#include <Windows.h>
#include <conio.h>

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


#include "Position.h"
#include "Cell.h"

#include "Board.h"
#include "Piece.h"
#include "Pawn.h"
#include "Rook.h"