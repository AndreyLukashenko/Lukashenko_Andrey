#include "EnterCagePoint.hpp"
#include "LeaveGageMode.hpp"


void EnterCagePoint::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (ghost_->getPosition() == ENTER_CAGE_POINT)
        {
            ghost_->setColor(ghost_->getInitialColor());
            ghost_->changeMode(new LeaveGageMode());
        }
        else
        {
            //ghost_->changeDirection(ghost_->getdirectionOpposite());
        }

    }
}


bool EnterCagePoint::isGateObstructionUp() const
{
    return true;
}


bool EnterCagePoint::isGateObstructionRight() const
{
    return true;
}


bool EnterCagePoint::isGateObstructionDown() const
{
    return true;
}


bool EnterCagePoint::isGateObstructionLeft() const
{
    return true;
}
