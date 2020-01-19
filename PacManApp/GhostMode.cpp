#include "GhostMode.hpp"


void GhostMode::setGhost(Ghost* ghost)
{
    ghost_ = ghost;
}


bool GhostMode::isGateObstructionUp() const
{
    CoordinatesXY position = ghost_->getPosition();

    return ConsoleUI::getInstance()->getChar(position.x, position.y - 1) != GATE;
}


bool GhostMode::isGateObstructionRight() const
{
    CoordinatesXY position = ghost_->getPosition();

    return ConsoleUI::getInstance()->getChar(position.x + 1, position.y) != GATE;
}


bool GhostMode::isGateObstructionDown() const
{
    CoordinatesXY position = ghost_->getPosition();

    return ConsoleUI::getInstance()->getChar(position.x, position.y + 1) != GATE;
}


bool GhostMode::isGateObstructionLeft() const
{
    CoordinatesXY position = ghost_->getPosition();

    return ConsoleUI::getInstance()->getChar(position.x - 1, position.y) != GATE;
}
