#include "LeaveGageMode.hpp"
#include "ChaseMode.h"


void LeaveGageMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (ghost_->getPosition() == LEAVE_CAGE_POINT)
        {
            ghost_->changeMode(new ChaseMode());
        }
        else
        {
            //ghost_->changeDirection(ghost_->getdirectionOpposite());
        }

    }
}


bool LeaveGageMode::isGateObstructionUp() const
{
    return true;
}


bool LeaveGageMode::isGateObstructionRight() const
{
    return true;
}


bool LeaveGageMode::isGateObstructionDown() const
{
    return true;
}


bool LeaveGageMode::isGateObstructionLeft() const
{
    return true;
}