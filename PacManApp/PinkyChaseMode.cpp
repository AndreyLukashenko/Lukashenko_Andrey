#include "PinkyChaseMode.hpp"


void PinkyChaseMode::targetObject()
{
    if (PacMan::getInstance()->getPacManMode() == PACMAN_MODE::GODMODE)
    {
        ChaseMode::targetObject();
    }
    else if (timer_.elapsedSeconds() > TIMER_CHASE_MODE)
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

            CoordinatesXY pacmanPosition = PacMan::getInstance()->getPosition();
            Direction pacmanDirection = PacMan::getInstance()->getDirection();

            CoordinatesXY target = directionMeasurement_.computeTargetPoint(pacmanDirection, pacmanPosition, PINKY_POSITION_OFFSET);

            Direction newDirection = directionMeasurement_.computePreferenceDirection(ghostPosition, target, possibleDirections);
            ghost_->changeDirection(newDirection);
        }
    }
}
