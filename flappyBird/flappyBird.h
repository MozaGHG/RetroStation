#include "../Position.h"
#include "bird.h"
#include "pipe.h"
#include <vector>
#pragma once


class FlappyBird
{
    public:
        FlappyBird();
        int Run();
        void Draw();
        void SetWalls();
        void ClearBoard();
        void SpawnPipe(int width, int height, Position pos);
        void GameOver();
        int HighScoreAuslesen();
        void HighScoreSchreiben(int NewScore);



    private:
        Bird bird;
        const int width = 50; const int height = 20;
        std::vector<std::vector<char>> board;
        int score = 0;
        std::vector<Pipe> pipes;
        
};