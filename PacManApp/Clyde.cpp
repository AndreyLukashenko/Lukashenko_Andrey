#include "Clyde.hpp"
#include "InitialMode.hpp"
#include "ClydeChaseMode.h"
#include "ScatterMode.hpp"

Clyde::Clyde() : Ghost(CLYDE_INITIAL_POINT, Direction::UP, CHARACTER_COLOR::CLYDE, CHARACTER_ICON::CLYDE)
{
    changeMode(getInitialMode());
}


Clyde& Clyde::getInstance()
{
    static Clyde instance_;

    return instance_;
}


void Clyde::reset()
{
    position_ = oldPosition_ = CLYDE_INITIAL_POINT;
    changeDirection(Direction::UP);
    color_ = CHARACTER_COLOR::CLYDE;
    changeMode(getInitialMode());
    drawCharacter();
}


std::unique_ptr<GhostMode> Clyde::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_CLYDE_FRUIT);
}


std::unique_ptr<GhostMode> Clyde::getChaseMode() const
{
    return std::make_unique<ClydeChaseMode>();
}


std::unique_ptr<GhostMode> Clyde::getScatterMode() const
{
    return std::make_unique<ScatterMode>(CLYDE_SCATTER_POINT);
}