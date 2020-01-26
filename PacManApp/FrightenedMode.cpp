#include "FrightenedMode.hpp"


void FrightenedMode::targetObject()
{
    if (ghost_ != nullptr)
    {
        if (PacMan::getInstance().getPacManMode() == PACMAN_MODE::NORMAL)
        {
            ghost_->setColor(ghost_->getInitialColor());
            ghost_->setCurrentSpeed(ghost_->getBasicSpeed());
            ghost_->changeMode(ghost_->getPreviousMode());
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

                Direction newDirection = possibleDirections[rand() % possibleDirections.size()];
                ghost_->changeDirection(newDirection);
            }
        }
    }
}


bool FrightenedMode::isPacManCollision()
{
    ghost_->setColor(CHARACTER_COLOR::ENTERMODE);
    ghost_->setCurrentSpeed(ghost_->getEnterCageSpeed());
    ghost_->changeMode(ghost_->getEnterCageMode());
    return false;
}


bool FrightenedMode::isGateObstructionUp() const
{
    return GhostMode::isGateObstructionUp();
}


bool FrightenedMode::isGateObstructionRight() const
{
    return GhostMode::isGateObstructionRight();
}


bool FrightenedMode::isGateObstructionDown() const
{
    return GhostMode::isGateObstructionDown();
}


bool FrightenedMode::isGateObstructionLeft() const
{
    return GhostMode::isGateObstructionLeft();
}
