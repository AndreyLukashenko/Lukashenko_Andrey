#include "Inky.hpp"
#include "InitialMode.hpp"
#include "PinkyChaseMode.hpp"
#include "ScatterMode.hpp"

Inky::Inky() : Ghost(INKY_INITIAL_POINT, Direction::DOWN, CHARACTER_COLOR::INKY, CHARACTER_ICON::INKY)
{
    changeMode(getInitialMode());
}


Inky& Inky::getInstance()
{
    static Inky instance_;

    return instance_;
}


void Inky::reset()
{
    position_ = oldPosition_ = INKY_INITIAL_POINT;
    changeDirection(Direction::DOWN);
    color_ = CHARACTER_COLOR::INKY;
    changeMode(getInitialMode());
    drawCharacter();
}


std::unique_ptr<GhostMode> Inky::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_INKY_FRUIT);
}


std::unique_ptr<GhostMode> Inky::getChaseMode() const
{
    return std::make_unique<PinkyChaseMode>();
}


std::unique_ptr<GhostMode> Inky::getScatterMode() const
{
    return std::make_unique<ScatterMode>(INKY_SCATTER_POINT);
}