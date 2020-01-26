#ifndef  GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "ConsoleUI.hpp"
#include "Timer.hpp"
#include "Maze.h"
#include "PacMan.hpp"
#include "Ghost.hpp"
#include "Blinky.hpp"
#include "Pinky.hpp"
#include "Inky.hpp"
#include "Clyde.hpp"

class Game
{
public:
    Game();
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;
    ~Game() = default;

    static int getFruitCount();
    void       run();

private:
    static int          fruitCount_;
    double				speedDelayPacMan_;
    int					lives_;
    int					score_;
    bool				gameOver_;
    Maze                maze_;
    PacMan&				pacman_;
    std::vector<Ghost*> ghosts_;
    Timer				timer_;
    Timer				timerPauseStart_;
    Timer				timerPacMan_;
    ConsoleUI&			console_;

    void updateGameField(float deltaTime);
    void pacmanMove();
    void ghostsMove(double speed);
    void checkForDeath();
    void drawCharacter() const;
    void showScore() const;
    void showLives() const;
    void resetGame();
    void gameOver();
    
};

#endif // ! GAME_H