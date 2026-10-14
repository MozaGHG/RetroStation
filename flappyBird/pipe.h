#include <vector>
#include "../Position.h"
#pragma once




class Pipe
{
    public:
        Pipe();
        void BuildCells();
        std::vector<std::vector<char>> addBoard(std::vector<std::vector<char>> board);
        void SetHeight(int height);
        void SetWidth(int width);
        void SetPos(Position pos);
        Position GetPos();
        std::vector<Position> GetCells();
        bool PlayerHit(Position playerpos);
        void addSpeed();
        void Move();

    private:
        int width = 5;
        int height = 0;
        Position pos = {0, 0};
        std::vector<Position> cells;
        float moveSpeed = 1.0f;
};
