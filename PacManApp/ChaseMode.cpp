#include "ChaseMode.h"
#include "FrightenedMode.hpp"


ChaseMode::ChaseMode()
{
    timer_.start();
}


void ChaseMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        ghost_->changeDirection(ghost_->getDirectionOpposite());
        ghost_->setColor(CHARACTER_COLOR::FRIGHTENED);
        ghost_->setPreviousMode(ghost_->getChaseMode());
        ghost_->changeMode(ghost_->getFrightenedMode());
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
