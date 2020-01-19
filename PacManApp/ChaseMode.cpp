#include "ChaseMode.h"
#include "FrightenedMode.hpp"


void ChaseMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (PacMan::getInstance()->getPacManMode() == PACMAN_MODE::GODMODE)
        {
            ghost_->changeDirection(ghost_->getdirectionOpposite());
            ghost_->setColor(CHARACTER_COLOR::FRIGHTENED);
            ghost_->changeMode(new FrightenedMode());
        }
        else
        {
            //ghost_->changeDirection(ghost_->getdirectionOpposite());
        }

    }
}


bool ChaseMode::isGateObstructionUp() const
{
    return GhostMode::isGateObstructionUp();
}


bool ChaseMode::isGateObstructionRight() const
{
    return GhostMode::isGateObstructionRight();
}


bool ChaseMode::isGateObstructionDown() const
{
    return GhostMode::isGateObstructionDown();
}


bool ChaseMode::isGateObstructionLeft() const
{
    return GhostMode::isGateObstructionLeft();
}
