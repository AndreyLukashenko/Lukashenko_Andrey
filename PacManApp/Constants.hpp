#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "CoordinatesXY.hpp"

// GAME
const float GAME_START_DELAY = 2.0F;
const float GAME_SPEED = 0.175f;
const int LIVES = 3;
const int FRUIT_COUNT = 240;
enum class COLOR
{
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    LIGHT_GRAY,
    DARK_GRAY,
    LIGHT_BLUE,
    LIGHT_GREEN,
    LIGHT_CYAN,
    LIGHT_RED,
    LIGHT_MAGENTA,
    YELLOW,
    WHITE
};

// MAZE 
const int FIELD_WIDTH = 28;
const int FIELD_HEIGHT = 35;

const char maze[FIELD_HEIGHT][FIELD_WIDTH + 1] = {
        "############################",
        "#************##************#",
        "#*####*#####*##*#####*####*#",
        "#$####*#####*##*#####*####$#",
        "#*####*#####*##*#####*####*#",
        "#**************************#",
        "#*####*##*########*##*####*#",
        "#*####*##*########*##*####*#",
        "#******##****##****##******#",
        "######*##### ## #####*######",
        "     #*##### ## #####*#     ",
        "     #*##    B     ##*#     ",
        "     #*## ###--### ##*#     ",
        "######*## #      # ##*######",
        "      *   #  I   #   *      ",
        "######*## #P    C# ##*######",
        "     #*## ######## ##*#     ",
        "     #*##          ##*#     ",
        "     #*## ######## ##*#     ",
        "######*## ######## ##*######",
        "#************##************#",
        "#*####*#####*##*#####*####*#",
        "#$####*#####*##*#####*####$#",
        "#***##*******> *******##***#",
        "###*##*##*########*##*##*###",
        "###*##*##*########*##*##*###",
        "#******##****##****##******#",
        "#*##########*##*##########*#",
        "#*##########*##*##########*#",
        "#**************************#",
        "############################",
        "#                          #",
        "# Score:          Lives:   #",
        "#                          #",
        "############################"
};

const char FRUIT = '*';
const char OBSTRUCTION = '#';
const char PILL = '$';
const char SPACE = ' ';
const char GATE = '-';

// CHARACTER
enum class Direction
{
    UP = 72,
    RIGHT = 77,
    DOWN = 80,
    LEFT = 75,
    NONE = 0
};

enum class CHARACTER_COLOR
{
    PACMAN = 14,
    BLINKY = 12,
    PINKY = 13,
    INKY = 11,
    CLYDE = 6,
    ENTERMODE = 15,
    FRIGHTENED = 9,
    NONE = 0
};

enum class CHARACTER_ICON
{
    PACMAN_UP = 'v',
    PACMAN_DOWN = '^',
    PACMAN_LEFT = '>',
    PACMAN_RIGHT = '<',
    BLINKY = 'B',
    PINKY = 'P',
    INKY = 'I',
    CLYDE = 'C',
    NONE = ' '
};

// PACMAN
const CoordinatesXY PACMAN_INITIAL_POSITION{ 13, 23 };
const double TIMER_PACMAN_GODMODE = 10.0;
enum class PACMAN_MODE
{
    NORMAL,
    GODMODE
};

// GHOSTS
const int LEAVE_BLINKY_FRUIT = 0;
const int LEAVE_PINKY_FRUIT = 5;
const int LEAVE_INKY_FRUIT = 40;
const int LEAVE_CLYDE_FRUIT = 75;

const int PINKY_POSITION_OFFSET = 4;
const int INKY_POSITION_OFFSET = 2;

const double DISTANCE_CLYDE_MODE = 8;

const double TIMER_CHASE_MODE = 20.0;
const double TIMER_SCATTER_MODE = 7.0;

// INITIAL POINTS
const CoordinatesXY BLINKY_INITIAL_POINT{ 13, 11 };
const CoordinatesXY PINKY_INITIAL_POINT{ 11, 15 };
const CoordinatesXY INKY_INITIAL_POINT{ 13, 14 };
const CoordinatesXY CLYDE_INITIAL_POINT{ 16, 15 };

// LEAVE CAGE POINT
const CoordinatesXY LEAVE_CAGE_POINT{ 13, 11 };

// ENTER CAGE POINT
const CoordinatesXY ENTER_CAGE_POINT{ 13, 14 };

// SCATTER POINTS
const CoordinatesXY BLINKY_SCATTER_POINT{ 25, -1 };
const CoordinatesXY PINKY_SCATTER_POINT{ 2, 1 };
const CoordinatesXY CLYDE_SCATTER_POINT{ 1, 31 };
const CoordinatesXY INKY_SCATTER_POINT{ 26, 31 };

#endif // !CONSTANTS_H

