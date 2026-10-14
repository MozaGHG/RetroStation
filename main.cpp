#include "snake/snake.h"
#include "flappyBird/flappyBird.h"
#include "tetris/tetris.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <windows.h>





void hide_cursor()
{
    HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursor_info;

    cursor_info.dwSize = 1;
    cursor_info.bVisible = FALSE;

    SetConsoleCursorInfo(console, &cursor_info);
}








int main()
{
    Snake snake;
    FlappyBird flappyBird;
    Tetris tetris;
    hide_cursor();

    std::string answer;
    std::cout << "Welches Game moechtest du spielen (Snake / Flappy Bird/ Tetris): ";
    std::getline(std::cin, answer);


    for (char &c : answer)
    {
        c = std::tolower((unsigned char)c);
    }
    std::cout << std::endl;

    if (answer == "snake")
    {
        return snake.Run();
    }

    else if (answer == "flappy bird" || answer == "flappybird")
    {
        return flappyBird.Run();
    }

    else if (answer == "tetris")
    {
        return tetris.Run();
    }
    
    std::cout << "Unbekanntes Spiel!" << std::endl;
    return 0;
}