#include "tetris.h"




Tetris::Tetris()
    :board(height, std::vector<char>(width, ' '))
{
    ClearBoard();
    SetWalls();
}



void Tetris::ClearBoard()
{
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            board[y][x] = ' ';
        }
    }
}



void Tetris::SetWalls()
{
    for (int x = 0; x < width; x++)
    {
        board[0][x] = '-';
        board[height - 1][x] = '-';
    }

    for (int y = 0; y < height; y++)
    {
        board[y][0] = '|';
        board[y][width - 1] = '|';
    }
}





void Tetris::NewTtile()
{
    Ttile tile;
    tile.SetRor('n');
    tiles.push_back(tile);
}


int Tetris::Run()
{
    while (true)
    {

    }
    return 0;
}