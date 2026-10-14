#include "../Position.h"
#include "T-tile.h"
#include <iostream>
#include <chrono>
#include <vector>
#pragma once

class Tetris
{
    public:
        Tetris();
        void clearBoard();
        void SetWalls();
        int Run();
        void NewTtile();


    private:
        int height = 20;
        int width = 20;
        std::vector<std::vector<char>> board;
        std::vector<Ttile> Ttiles = {};

        
};