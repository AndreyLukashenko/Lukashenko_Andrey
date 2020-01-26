#include "Maze.h"

Maze::Maze() : console_(ConsoleUI::getInstance())
{
    mazeInitialize();
}


void Maze::mazeInitialize()
{
    for (int x = 0; x < FIELD_HEIGHT; ++x)
    {
        for (int y = 0; y < FIELD_WIDTH + 1; ++y)
        {
            maze_[x][y] = maze[x][y];
        }
    }
}


void Maze::drawMaze() const
{
    for (int y = 0; y < FIELD_HEIGHT; ++y)
    {
        for (int x = 0; x < FIELD_WIDTH; ++x)
        {
            switch (maze_[y][x])
            {
            case FRUIT:
                console_.setChar(x, y, maze_[y][x], COLOR::WHITE);
                break;
            case OBSTRUCTION:
                console_.setChar(x, y, maze_[y][x], COLOR::BLUE);
                break;
            case PILL:
                console_.setChar(x, y, maze_[y][x], COLOR::GREEN);
                break;
            case SPACE:
                console_.setChar(x, y, maze_[y][x], COLOR::BLACK);
                break;
            default:
                console_.setChar(x, y, maze_[y][x], COLOR::WHITE);
                break;
            }
        }
    }
}


void Maze::setChar(int x, int y, char c)
{
    maze_[y][x] = c;
}


char Maze::getChar(int x, int y) const
{
    return maze_[y][x];
}
