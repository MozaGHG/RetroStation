#include "flappyBird.h"
#include <fstream>
#include <conio.h>
#include <chrono>
#include <random>
#include <iostream>





FlappyBird::FlappyBird()
    :board(height, std::vector<char>(width, ' '))
{
    ClearBoard();
    SetWalls();
}




int FlappyBird::HighScoreAuslesen()
{
    int erg;
    std::ifstream in("highscore.txt");
    if (in.is_open())
    {
        in >> erg;
        return erg;
    }
    else
    {
        return 0;
    }
}




void FlappyBird::SpawnPipe(int width, int height, Position pos)
{
    Pipe pipe;
    pipe.SetWidth(width);
    pipe.SetHeight(height);
    pipe.SetPos(pos);
    pipes.push_back(pipe);
}


void FlappyBird::HighScoreSchreiben(int newScore)
{
    std::ofstream out("highscore.txt");
    out << newScore;
}




void FlappyBird::GameOver()
{
    std::cout << "Game Over!" << std::endl;
    system("pause");

    if (score > HighScoreAuslesen())
    {
        HighScoreSchreiben(score);
    }

    score = 0;
    pipes.clear();
    bird.Reset();
}




void FlappyBird::ClearBoard()
{
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size() ; x++)
        {
            board[y][x] = ' ';
        }
    }
}


void FlappyBird::SetWalls()
{
    for (int x = 0; x < width; x++)
    {
        board[0][x] = '-';
        board[height - 1][x] = '-';
    }

    for (int y = 0; y < height; y++)
    {
        board[y][0] = '|';
        board[y][width - 1] = '|';
    }
}





void FlappyBird::Draw()
{
    ClearBoard();
    SetWalls();
    
    for (Pipe pipe : pipes)
    {
        board = pipe.addBoard(board);
    }

    Position bp = bird.GetPos();

    if (bp.y > 0 && bp.y < height - 1 && bp.x > 0 && bp.x < width - 1)
    {
        board[bp.y][bp.x] = '@';
    }


    std::cout << "\033[H";
    for (int y = 0; y < board.size(); y++)
    {
        for (int x = 0; x < board[y].size(); x++)
        {
            std::cout << board[y][x];
        }
        std::cout << "\n";
    
    }
    std::cout << "\n" << "                      Score: " << score << std::endl;
}





int FlappyBird::Run()
{
    int highscore = HighScoreAuslesen();
    system("cls");
    std::cout << "Highscore: " << highscore << std::endl;
    system("pause");

    auto LastDraw = std::chrono::steady_clock::now();
    auto lastSpawn = std::chrono::steady_clock::now();

    std::mt19937 rng(std::random_device{}());
    std::uniform_int_distribution<int> distSec(1, 3);
    std::uniform_int_distribution<int> distH(5, 10);
    std::uniform_int_distribution<int> distDecke(0, 1);
    auto nextSpawnIn = std::chrono::seconds(distSec(rng));

    while (true)
    {   
        if (_kbhit())
        {
            char key = _getch();
            if (key == ' ' || key == 'w')
            {
                bird.Jump();
            }

        }

        



        auto now = std::chrono::steady_clock::now();

            if (now - lastSpawn >= nextSpawnIn)
            {
                int h = distH(rng);
                bool decke = (distDecke(rng) == 0);
                int y = decke ? 1 : height - 1 - h;
                SpawnPipe(5, h, {width - 1 - 5, y});
                lastSpawn = now;
                nextSpawnIn = std::chrono::seconds(distSec(rng));
            }

        
            if (now - LastDraw >= std::chrono::milliseconds(200))
            {

                for (int i = (int)pipes.size() - 1; i >= 0; --i)
                {
                    if (pipes[i].GetPos().x + 5 <= 1)
                    {
                        pipes.erase(pipes.begin() + i);
                        score++;
                    }
                }

                for (Pipe &pipe : pipes)
                {
                    pipe.addSpeed();
                    pipe.Move();
                    


                    if (pipe.PlayerHit(bird.GetPos()))
                    {
                        GameOver();
                    }

                }
                bird.Fall();
                if (bird.GetPos().y <= 0 || bird.GetPos().y >= height - 1)
                {
                    GameOver();
                }
                Draw();
                LastDraw = now;
            }

        

        
    }

    
    return 0;
}

