#include "InkyChaseMode.hpp"
#include "Blinky.hpp"


void InkyChaseMode::targetObject()
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
            Direction pacmanDirection = PacMan::getInstance().getDirection();
            CoordinatesXY pacmanPointOffset = directionMeasurement_.computeTargetPoint(pacmanDirection, pacmanPosition, INKY_POSITION_OFFSET);
            CoordinatesXY blinkyPosition = Blinky::getInstance().getPosition();
            CoordinatesXY difference = { pacmanPointOffset.x - blinkyPosition.x, pacmanPointOffset.y - blinkyPosition.y };
            CoordinatesXY differenceLengthen = { difference.x * 2, difference.y * 2 };
            CoordinatesXY target = { blinkyPosition.x + differenceLengthen.x, blinkyPosition.y + differenceLengthen.y };

            Direction newDirection = directionMeasurement_.computePreferenceDirection(ghostPosition, target, possibleDirections);
            ghost_->changeDirection(newDirection);
        }
    }
}
