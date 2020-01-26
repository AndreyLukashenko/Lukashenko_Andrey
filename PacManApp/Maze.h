#ifndef MAZE_H
#define MAZE_H

#include "Constants.hpp"
#include "ConsoleUI.hpp"

class Maze
{
public:
    Maze();
    Maze(const Maze&) = delete;
    Maze& operator=(const Maze&) = delete;
    ~Maze() = default;

    void drawMaze() const;
    void setChar(int x, int y, char c);
    char getChar(int x, int y) const;

private:
    char       maze_[FIELD_HEIGHT][FIELD_WIDTH + 1];
    ConsoleUI& console_;

    void       mazeInitialize();
};

#endif // !MAZE_H



