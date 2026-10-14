#include "pipe.h"





Pipe::Pipe()
{
    BuildCells();
}


void Pipe::BuildCells()
{
    cells.clear();
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            cells.push_back({x, y});
        }
    }
}





std::vector<std::vector<char>> Pipe::addBoard(std::vector<std::vector<char>> board)
{
    for (Position c : cells)
    {
        int ax = pos.x + c.x;
        int ay = pos.y + c.y;
        if (ay > 0 && ay < (int)board.size() - 1 && ax > 0 && ax < (int)board[ay].size() - 1)
        {
            board[ay][ax] = '#';
        }
    }
    return board;
}


void Pipe::SetHeight(int height)
{
    this->height = height;
    BuildCells();
}


void Pipe::SetWidth(int width)
{
    this->width = width;
    BuildCells();
}



void Pipe::SetPos(Position pos)
{
    this->pos = pos;
}

Position Pipe::GetPos()
{
    return pos;
}

std::vector<Position> Pipe::GetCells()
{
    return cells;
}

bool Pipe::PlayerHit(Position playerpos)
{
    for (Position c : cells)
    {
        if (pos.x + c.x == playerpos.x && pos.y + c.y == playerpos.y)
        {
            return true;
        }
    }
    return false;
}

void Pipe::addSpeed()
{
    moveSpeed += 0.2f;
}


void Pipe::Move()
{
    pos.x -= moveSpeed;
}