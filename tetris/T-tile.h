#include "block.h"
#include "../Position.h"
#include <vector>
#pragma once






class Ttile
{
    public:
        Position GetLowestBlockPos();
        void Rotate();
        char GetRot();
        std::vector<Block> GetBlocks();
        void SetPos(Position Block1Pos);
        std::vector<Position> GetOffset();
        void SetPos(Position block4pos);


    private:
        std::vector<Block> blocks = {Block(), Block(), Block(), Block(), Block()};
        std::vector<Position> blockOffset;
        char rotation;


};