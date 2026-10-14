#include "../Position.h"
#pragma once

class Bird
{
    public:
        Position GetPos();
        void Jump();
        void Fall();
        void SetPos(Position pos);
        void Reset();

    private:
        Position pos = {5, 5};
        int velocity = 0; int gravity = 1;
};