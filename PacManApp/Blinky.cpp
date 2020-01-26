#include "Blinky.hpp"
#include "InitialMode.hpp"
#include "BlinkyChaseMode.hpp"
#include "ScatterMode.hpp"

Blinky::Blinky() : Ghost(BLINKY_INITIAL_POINT, Direction::LEFT, CHARACTER_COLOR::BLINKY, CHARACTER_ICON::BLINKY)
{
    changeMode(getChaseMode());
}


Blinky& Blinky::getInstance()
{
    static Blinky instance_;

    return instance_;
}


void Blinky::reset()
{
    position_ = oldPosition_ = BLINKY_INITIAL_POINT;
    changeDirection(Direction::LEFT);
    color_ = CHARACTER_COLOR::BLINKY;
    changeMode(getChaseMode());
    drawCharacter();
}


std::unique_ptr<GhostMode> Blinky::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_BLINKY_FRUIT);
}


std::unique_ptr<GhostMode> Blinky::getChaseMode() const
{
    return std::make_unique<BlinkyChaseMode>();
}


std::unique_ptr<GhostMode> Blinky::getScatterMode() const
{
    return std::make_unique<ScatterMode>(BLINKY_SCATTER_POINT);
}