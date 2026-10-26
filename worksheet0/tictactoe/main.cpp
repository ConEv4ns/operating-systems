#include <iostream>
#include "game.h"

int main()
{
    char board[9] =
    {
        '1','2','3',
        '4','5','6',
        '7','8','9'
    };

    int position;

    for(int turn = 0; turn < 9; turn++)
    {
        printBoard(board);

        if(turn % 2 == 0)
        {
            std::cout << "Player X, choose a position: ";
            std::cin >> position;

            placeMove(board, position - 1, 'X');
        }
        else
        {
            std::cout << "Player O, choose a position: ";
            std::cin >> position;

            placeMove(board, position - 1, 'O');
        }
    }

    std::cout << "\nFinal Board:\n";

    printBoard(board);

    return 0;
}