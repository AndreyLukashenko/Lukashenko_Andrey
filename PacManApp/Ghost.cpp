#include "Ghost.hpp"
#include "LeaveCageMode.hpp"
#include "FrightenedMode.hpp"
#include "EnterCageMode.hpp"

Ghost::Ghost(CoordinatesXY position, Direction direction, CHARACTER_COLOR color, CHARACTER_ICON icon) :
    Character(position, direction, color, icon), initialColor_(color), directionOpposite_(Direction::NONE), mode_(nullptr)
{
    setCurrentSpeed(getBasicSpeed());
    changeDirection(direction);
}


void Ghost::changeMode(std::unique_ptr<GhostMode> mode)
{
    mode_.reset(mode.release());
    if (mode_ != nullptr) 
    {
        mode_->setGhost(this);
    }
    
}


void Ghost::targetObject()
{
    if (mode_ != nullptr) {
        mode_->targetObject();
    }
}


void Ghost::move()
{
    Character::move();
    targetObject();
}


void Ghost::changeDirection(Direction newDirection)
{
    direction_ = newDirection;

    switch (newDirection)
    {
    case Direction::UP:
        directionOpposite_ = Direction::DOWN;
        break;
    case Direction::DOWN:
        directionOpposite_ = Direction::UP;
        break;
    case Direction::LEFT:
        directionOpposite_ = Direction::RIGHT;
        break;
    case Direction::RIGHT:
        directionOpposite_ = Direction::LEFT;
        break;
    default:
        break;
    }
}


bool Ghost::isCollisionUp() const
{
    return Character::isCollisionUp() && mode_->isGateObstructionUp();
}


bool Ghost::isCollisionDown() const
{
    return Character::isCollisionDown() && mode_->isGateObstructionDown();
}


bool Ghost::isCollisionLeft() const
{
    return Character::isCollisionLeft() && mode_->isGateObstructionLeft();
}


bool Ghost::isCollisionRight() const
{
    return Character::isCollisionRight() && mode_->isGateObstructionRight();
}


bool Ghost::isPacManCollision() const
{
    return mode_->isPacManCollision();
}


void Ghost::setCurrentSpeed(double currentSpeed)
{
    currentSpeed_ = currentSpeed;
}


void Ghost::setSpeedDelay(double speedDelay)
{
    if (speedDelay_ > currentSpeed_)
    {
        speedDelay_ = 0;
    }
    else
    {
        speedDelay_ += speedDelay;
    }
}


void Ghost::setPreviousMode(std::unique_ptr<GhostMode> previousMode)
{
    previousMode_.reset(previousMode.release());
}


CHARACTER_COLOR Ghost::getInitialColor() const
{
    return initialColor_;
}


Direction Ghost::getDirectionOpposite() const
{
    return directionOpposite_;
}


double Ghost::getSpeedDelay() const
{
    return speedDelay_;
}


double Ghost::getCurrentSpeed() const
{
    return currentSpeed_;
}


double Ghost::getBasicSpeed() const
{
    return GHOST_BASIC_SPEED;
}


double Ghost::getFrightenedSpeed() const
{
    return GHOST_FRIGHTENED_SPEED;
}


double Ghost::getEnterCageSpeed() const
{
    return GHOST_ENTERCAGE_SPEED;
}


std::unique_ptr<GhostMode> Ghost::getMode()
{
    return std::move(mode_);
}


std::unique_ptr<GhostMode> Ghost::getPreviousMode()
{
    return std::move(previousMode_);
}


std::unique_ptr<GhostMode> Ghost::getLeaveCageMode() const
{
    return std::make_unique<LeaveCageMode>();
}


std::unique_ptr<GhostMode> Ghost::getFrightenedMode() const
{
    return std::make_unique<FrightenedMode>();
}


std::unique_ptr<GhostMode> Ghost::getEnterCageMode() const
{
    return std::make_unique<EnterCageMode>();
}
