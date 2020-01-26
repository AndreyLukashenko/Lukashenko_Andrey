#include "LeaveCageMode.hpp"
#include "ChaseMode.h"


void LeaveCageMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (ghost_->getPosition() == LEAVE_CAGE_POINT)
        {
            ghost_->changeMode(ghost_->getChaseMode());
        }
        else
        {
            std::vector<Direction> possibleDirections = directionMeasurement_.computePossibleDirections(*ghost_);
            if (possibleDirections.size() == 1)
            {
                ghost_->changeDirection(possibleDirections[0]);
            }
            else
            {
                CoordinatesXY ghostPosition = ghost_->getPosition();
                CoordinatesXY target = LEAVE_CAGE_POINT;

                Direction newDirection = directionMeasurement_.computePreferenceDirection(ghostPosition, target, possibleDirections);
                ghost_->changeDirection(newDirection);
            }
        }

    }
}


bool LeaveCageMode::isPacManCollision()
{
    return false;
}


bool LeaveCageMode::isGateObstructionUp() const
{
    return true;
}


bool LeaveCageMode::isGateObstructionRight() const
{
    return true;
}


bool LeaveCageMode::isGateObstructionDown() const
{
    return true;
}


bool LeaveCageMode::isGateObstructionLeft() const
{
    return true;
}