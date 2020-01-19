#include "FrightenedMode.hpp"


void FrightenedMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (PacMan::getInstance()->getPacManMode() == PACMAN_MODE::NORMAL)
        {
            ghost_->setColor(ghost_->getInitialColor());
            ghost_->changeMode(ghost_->getPreviousMode());
        }
        else
        {
            //ghost_->changeDirection(ghost_->getdirectionOpposite());
        }

    }
}


bool FrightenedMode::isGateObstructionUp() const
{
    return GhostMode::isGateObstructionUp();
}


bool FrightenedMode::isGateObstructionRight() const
{
    return GhostMode::isGateObstructionRight();
}


bool FrightenedMode::isGateObstructionDown() const
{
    return GhostMode::isGateObstructionDown();
}


bool FrightenedMode::isGateObstructionLeft() const
{
    return GhostMode::isGateObstructionLeft();
}
