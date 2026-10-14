#include "../Position.h"
#pragma once


class Block
{
    public:
        Position GetPos();
        void SetPos(Position pos);

        
    private:
        Position pos;
};