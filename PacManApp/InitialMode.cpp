#include "InitialMode.hpp"
#include "LeaveCageMode.hpp"


InitialMode::InitialMode(int fruitLeave) : GhostMode(), fruitLeave_(fruitLeave)
{

}


void InitialMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (fruitLeave_ <= PacMan::getInstance()->getFruitEaten())
        {
            ghost_->changeMode(ghost_->getLeaveCageMode());
        }
        else
        {
            ghost_->changeDirection(ghost_->getDirectionOpposite());
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
