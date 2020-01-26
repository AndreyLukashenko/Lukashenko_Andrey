#include "BlinkyChaseMode.hpp"


void BlinkyChaseMode::targetObject()
{
    if (timer_.elapsedSeconds() > TIMER_CHASE_MODE)
    {
        ghost_->changeMode(ghost_->getScatterMode());
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
            CoordinatesXY target = PacMan::getInstance().getPosition();

            Direction newDirection = directionMeasurement_.computePreferenceDirection(ghostPosition, target, possibleDirections);
            ghost_->changeDirection(newDirection);
        }
    }
}
