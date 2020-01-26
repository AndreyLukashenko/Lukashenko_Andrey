#include "Pinky.hpp"
#include "InitialMode.hpp"
#include "PinkyChaseMode.hpp"
#include "ScatterMode.hpp"

Pinky::Pinky() : Ghost(PINKY_INITIAL_POINT, Direction::UP, CHARACTER_COLOR::PINKY, CHARACTER_ICON::PINKY)
{
    changeMode(getInitialMode());
}


Pinky& Pinky::getInstance()
{
    static Pinky instance_;

    return instance_;
}


void Pinky::reset()
{
    position_ = oldPosition_ = PINKY_INITIAL_POINT;
    changeDirection(Direction::UP);
    color_ = CHARACTER_COLOR::PINKY;
    changeMode(getInitialMode());
    drawCharacter();
}


std::unique_ptr<GhostMode> Pinky::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_PINKY_FRUIT);
}


std::unique_ptr<GhostMode> Pinky::getChaseMode() const
{
    return std::make_unique<PinkyChaseMode>();
}


std::unique_ptr<GhostMode> Pinky::getScatterMode() const
{
    return std::make_unique<ScatterMode>(PINKY_SCATTER_POINT);
}
