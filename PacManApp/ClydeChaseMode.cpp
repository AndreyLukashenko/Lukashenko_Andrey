#include "ClydeChaseMode.h"

void ClydeChaseMode::targetObject()
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
            CoordinatesXY pacmanPosition = PacMan::getInstance().getPosition();
            double distance = directionMeasurement_.computeDistance(ghostPosition, pacmanPosition);

            CoordinatesXY target;
            if (distance > DISTANCE_CLYDE_MODE)
                target = pacmanPosition;
            else
                target = CLYDE_SCATTER_POINT;

            Direction newDirection = directionMeasurement_.computePreferenceDirection(ghostPosition, target, possibleDirections);
            ghost_->changeDirection(newDirection);
        }
    }
}
