#include "Game.hpp"
#include "GhostMode.hpp"

int Game::fruitCount_ = FRUIT_COUNT;

Game::Game() : lives_(LIVES), score_(0), speedDelayPacMan_(0), gameOver_(false), pacman_(PacMan::getInstance()),
    console_(ConsoleUI::getInstance())
{
    Ghost& blinky = Blinky::getInstance();
    ghosts_.push_back(&blinky);

    Ghost& pinky = Pinky::getInstance();
    ghosts_.push_back(&pinky);

    Ghost& inky = Inky::getInstance();
    ghosts_.push_back(&inky);

    Ghost& clyde = Clyde::getInstance();
    ghosts_.push_back(&clyde);
}


void Game::run() 
{
    int deltaTime = 0;
    maze_.drawMaze();
    while (true) {
        timer_.start();
        if (!gameOver_)
            updateGameField(static_cast<float>(deltaTime) / 1000.0f);
        console_.render();
        Sleep(1);

        while (true)
        {
            deltaTime = timer_.elapsedMilliseconds();
            if (deltaTime > 20)
                break;
        }
    }
}


void Game::updateGameField(float deltaTime)
{
    speedDelayPacMan_ += deltaTime;

    if (timerPauseStart_.elapsedSeconds() > GAME_START_DELAY)
    {
        if (speedDelayPacMan_ > GAME_SPEED) {
            speedDelayPacMan_ = 0;
            pacmanMove();
            checkForDeath();
        }
        ghostsMove(deltaTime);
        maze_.drawMaze();
        drawCharacter();
        showScore();
        showLives();
        gameOver();
    }
}


void Game::pacmanMove()
{
    if (pacman_.getPacManMode() == PACMAN_MODE::GODMODE)
    {
        if (timerPacMan_.elapsedSeconds() > TIMER_PACMAN_GODMODE)
        {
            pacman_.setPacManMode(PACMAN_MODE::NORMAL);
        }
    }

    pacman_.move();

    CoordinatesXY position = pacman_.getPosition();
    if (maze_.getChar(position.x, position.y) == FRUIT)
    {
        maze_.setChar(position.x, position.y, SPACE);
        fruitCount_--;
        score_ += 10;
    }
    else if (maze_.getChar(position.x, position.y) == PILL)
    {
        maze_.setChar(position.x, position.y, SPACE);
        score_ += 50;
        pacman_.setPacManMode(PACMAN_MODE::GODMODE);
        timerPacMan_.start();
        for (auto ghost : ghosts_)
        {
            ghost->changeDirection(ghost->getDirectionOpposite());
            ghost->setColor(CHARACTER_COLOR::FRIGHTENED);
            ghost->setPreviousMode(ghost->getMode());
            ghost->setCurrentSpeed(ghost->getFrightenedSpeed());
            ghost->changeMode(ghost->getFrightenedMode());
        }
    }

    console_.render();
}


void Game::ghostsMove(double speed)
{
    for (auto ghost : ghosts_)
    {
        if (ghost != nullptr)
        {
            ghost->setSpeedDelay(speed);
            if (ghost->getSpeedDelay() > ghost->getCurrentSpeed())
            {
                ghost->move();
            }
        }
    }
    checkForDeath();
}


void Game::checkForDeath()
{
    for (auto ghost : ghosts_)
    {
        if (ghost != nullptr)
        {
            if (ghost->getPosition() == pacman_.getPosition())
            {
                if (ghost->isPacManCollision())
                {
                    --lives_;
                    if (lives_ > 0)
                    {
                        resetGame();
                    }
                }
            }
        }
    }
}


void Game::drawCharacter() const
{
    pacman_.drawCharacter();
    for (auto ghost : ghosts_)
    {
        if (ghost != nullptr)
        {
            ghost->drawCharacter();
        }
    }
}


void Game::showScore() const 
{
    std::string score = std::to_string(score_);
    for (int i = 0; i < score.length(); ++i) {
        console_.setChar(8 + i, 32, score[i], COLOR::RED);
    }
}


void Game::showLives() const 
{
    std::string lives = std::to_string(lives_);
    console_.setChar(25, 32, lives[0], COLOR::RED);
}


void Game::resetGame() 
{
    for (auto ghost : ghosts_) {
        if (ghost != nullptr)
            ghost->reset();
    }
    pacman_.reset();
    timerPauseStart_.start();
}


void Game::gameOver() 
{
    if (lives_ <= 0) {
        gameOver_ = true;
        std::string message = "You lose";
        for (int i = 0; i < message.length(); ++i) {
            console_.setChar(10 + i, 17, message[i], COLOR::RED);
        }
    }
    if (fruitCount_ == 0) {
        gameOver_ = true;
        std::string message = "You win";
        for (int i = 0; i < message.length(); ++i) {
            console_.setChar(10 + i, 17, message[i], COLOR::LIGHT_GREEN);
        }
    }
}

int Game::getFruitCount()
{
    return fruitCount_;
}
