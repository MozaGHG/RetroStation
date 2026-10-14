#include "T-tile.h"


Position Ttile::GetLowestBlockPos()
{
    Position lowest = blocks[0].GetPos();
    for (int i = 1; i < 4; i++)
        if (blocks[i].GetPos().y > lowest.y)
            lowest = blocks[i].GetPos();
    return lowest;
}



void Ttile::Rotate()
{
    switch(rotation)
    {
        case 'n': rotation = 'e'; break;
        case 'e': rotation = 's'; break;
        case 's': rotation = 'w'; break;
        case 'w': rotation = 'n'; break;
    }
}



char Ttile::GetRot()
{
    return rotation;
}


std::vector<Block> Ttile::GetBlocks()
{
    return blocks;
}



void Ttile::SetPos(Position Block1Pos)
{
    for (int i = 0; i < blocks.size(); i++)
    {
        blocks[i].SetPos(Block1Pos + blockOffset[i]);
    }
}


std::vector<Position> Ttile::GetOffset()
{
    switch(rotation)
    {
         case 'n': return {{-1, -1}, {0, -1}, {1, -1}, {0, 0}, {0, 1}};
         case 'e': return {{1, -1}, {1, 0}, {1, 1}, {0, 0}, {-1, 0}};
         case 's': return {{1, 1}, {0, 1}, {-1, 1}, {0, 0}, {0, -1}};
         case 'w': return {{-1, 1}, {-1, 0}, {-1, -1}, {0, 0}, {1, 0}};
    }
}


void Ttile::SetPos(Position  block4pos)
{
    blocks[3].SetPos(block4pos);
}