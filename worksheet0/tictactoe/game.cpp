#include <iostream>
#include "game.h"

void printBoard(char* board)
{
    std::cout << "\n";

    std::cout << board[0] << "|" << board[1] << "|" << board[2] << "\n";
    std::cout << "-+-+-\n";
    std::cout << board[3] << "|" << board[4] << "|" << board[5] << "\n";
    std::cout << "-+-+-\n";
    std::cout << board[6] << "|" << board[7] << "|" << board[8] << "\n";

    std::cout << "\n";
}

void placeMove(char* board, int pos, char symbol)
{
    board[pos] = symbol;
}