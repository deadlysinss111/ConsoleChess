#include "pch.h"

void ChangePlayerTurn(COLOR* turn) {
    if (*turn == WHITE) *turn = BLACK;
    else *turn = WHITE;
}

int main()
{
    Board board;
    bool runing = true;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = { 1, 7 };
    COLOR playerTurn = WHITE;
    Cell* currentTarget = nullptr;

    while (runing) {
        system("cls");
        SetConsoleCursorPosition(hConsole, COORD{0, 0});
        board.ResetColor();
        board.Display(&hConsole);
        SetConsoleCursorPosition(hConsole, pos);
        
        int input = _getch();

        switch (input) {
        case UP:
            pos.Y -= 1;
            break;
        case DOWN:
            pos.Y += 1;
            break;
        case RIGHT:
            pos.X += 2;
            break;
        case LEFT:
            pos.X -= 2;
            break;
        case CONFIRM: {
            Cell* target = board.GetCellAt(pos.X / 2, pos.Y);
            
            switch (target->color) {
            case C_EMPTY:
                break;

            case C_PLAYABLE:
                board.MoveFromTo(currentTarget, target);
                board.ResetPlayableCells();
                currentTarget = nullptr;
                ChangePlayerTurn(&playerTurn);
                break;

            case C_WHITE:
                if (playerTurn == BLACK) continue;

                currentTarget = target;
                target->occupedBy->SetAccesibleCellsToPlayable(&board);
                break;

            case C_BLACK:
                if (playerTurn == WHITE) continue;

                currentTarget = target;
                target->occupedBy->SetAccesibleCellsToPlayable(&board);
                break;

            default:
                break;
            }
        }
            break;
        default:
            break;
        }
    }
}
