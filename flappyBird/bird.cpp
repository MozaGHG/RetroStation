#include "bird.h"

Position Bird::GetPos()
{
    return pos;
}

void Bird::SetPos(Position pos)
{
    this->pos = pos;
}

void Bird::Reset()
{
    pos = {5, 5};
    velocity = 0;
}

void Bird::Jump()
{
    velocity = -3;
}

void Bird::Fall()
{
    velocity += gravity;
    pos.y += velocity;
}