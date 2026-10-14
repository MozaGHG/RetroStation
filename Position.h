#pragma once

struct Position
{
    int x;
    int y;

    bool operator==(const Position& other) const
    {
        return x == other.x && y == other.y;
    }
    
    Position operator+(const Position& other) const
    {
        return {x + other.x, y + other.y};
    }

    Position operator-(const Position& other) const
    {
        return {x - other.x, y - other.y};
    }
};