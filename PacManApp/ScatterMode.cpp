#include "ScatterMode.hpp"
#include "FrightenedMode.hpp"

ScatterMode::ScatterMode(CoordinatesXY cornerPoint) : GhostMode(), cornerPoint_(cornerPoint)
{

}


void ScatterMode::targetObject()
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
            
        }

    }
}


bool ScatterMode::isGateObstructionUp() const
{
    return GhostMode::isGateObstructionUp();
}


bool ScatterMode::isGateObstructionRight() const
{
    return GhostMode::isGateObstructionRight();
}


bool ScatterMode::isGateObstructionDown() const
{
    return GhostMode::isGateObstructionDown();
}


bool ScatterMode::isGateObstructionLeft() const
{
    return GhostMode::isGateObstructionLeft();
}
