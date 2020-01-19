#include "InitialMode.hpp"
#include "LeaveGageMode.hpp"


InitialMode::InitialMode(int fruitLeave) : GhostMode(), fruitLeave_(fruitLeave)
{

}


void InitialMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (fruitLeave_ == PacMan::getInstance()->getFruitEaten())
        {
            ghost_->changeMode(new LeaveGageMode());
        }
        else
        {
            ghost_->changeDirection(ghost_->getdirectionOpposite());
        }
        
    }
}


bool InitialMode::isGateObstructionUp() const
{
    return true;
}


bool InitialMode::isGateObstructionRight() const
{
    return true;
}


bool InitialMode::isGateObstructionDown() const
{
    return true;
}


bool InitialMode::isGateObstructionLeft() const
{
    return true;
}
