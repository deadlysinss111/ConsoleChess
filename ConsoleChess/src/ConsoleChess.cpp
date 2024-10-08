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

#ifdef _DEMO
    int playsLeft = 4;
#endif

    while (runing) {
        system("cls");
        SetConsoleCursorPosition(hConsole, COORD{0, 0});
        board.ResetColor();
        board.Display(&hConsole);

        std::string str("\nturn player is : ");
        str.append(playerTurn == WHITE ? "white" : "black");
        LOG(str);
        
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

#ifdef _DEMO
                --playsLeft;
#endif

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

#ifdef _DEMO
        if (playsLeft <= 0) {
            system("cls");
            SetConsoleCursorPosition(hConsole, COORD{ 0, 0 });
            board.ResetColor();
            board.Display(&hConsole);

            SetConsoleCursorPosition(hConsole, COORD{ 0, 10 });
            std::cout << "You reched the maximum content of the demo version. 10 boxes for the full version available on steam :)";
            runing = false;
        }
#endif

    }

#ifdef _DEBUG

    _CrtDumpMemoryLeaks();

#endif
    return 0;
}
