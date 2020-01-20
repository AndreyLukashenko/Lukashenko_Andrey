#include "ScatterMode.hpp"
#include "FrightenedMode.hpp"

ScatterMode::ScatterMode(CoordinatesXY cornerPoint) : GhostMode(), cornerPoint_(cornerPoint)
{
    timer_.start();
}


void ScatterMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (PacMan::getInstance()->getPacManMode() == PACMAN_MODE::GODMODE)
        {
            ghost_->changeDirection(ghost_->getDirectionOpposite());
            ghost_->setColor(CHARACTER_COLOR::FRIGHTENED);
            ghost_->setPreviousMode(ghost_->getScatterMode());
            ghost_->changeMode(ghost_->getFrightenedMode());
        }
        else if (timer_.elapsedSeconds() > TIMER_SCATTER_MODE)
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
                CoordinatesXY target = cornerPoint_;

                Direction newDirection = directionMeasurement_.computePreferenceDirection(ghostPosition, target, possibleDirections);
                ghost_->changeDirection(newDirection);
            }
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
