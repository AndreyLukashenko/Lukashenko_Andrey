#include "EnterCageMode.hpp"
#include "LeaveCageMode.hpp"


void EnterCageMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (ghost_->getPosition() == ENTER_CAGE_POINT)
        {
            ghost_->setColor(ghost_->getInitialColor());
            ghost_->changeMode(ghost_->getLeaveCageMode());
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
                CoordinatesXY target = ENTER_CAGE_POINT;

                Direction newDirection = directionMeasurement_.computePreferenceDirection(ghostPosition, target, possibleDirections);
                ghost_->changeDirection(newDirection);
            }
        }

    }
}


bool EnterCageMode::isGateObstructionUp() const
{
    return true;
}


bool EnterCageMode::isGateObstructionRight() const
{
    return true;
}


bool EnterCageMode::isGateObstructionDown() const
{
    return true;
}


bool EnterCageMode::isGateObstructionLeft() const
{
    return true;
}
