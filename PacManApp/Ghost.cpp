#include "Ghost.hpp"
#include "LeaveCageMode.hpp"
#include "FrightenedMode.hpp"
#include "EnterCageMode.hpp"

Ghost::Ghost(CoordinatesXY position, Direction direction, CHARACTER_COLOR color, CHARACTER_ICON icon) :
    Character(position, direction, color, icon), initialColor_(color), directionOpposite_(Direction::NONE), mode_(nullptr)
{
	changeDirection(direction);
}


void Ghost::changeMode(std::unique_ptr<GhostMode> mode)
{
	mode_.reset(mode.release());
	if (mode_ != nullptr) 
	{
		mode_->setGhost(this);
		mode_->targetObject();
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
	targetObject();

	Character::move();

	if (oldChar_ == FRUIT || oldChar_ == GATE)
		console_->setChar(oldPosition_.x, oldPosition_.y, oldChar_, COLOR::WHITE);
	else if (oldChar_ == PILL)
		console_->setChar(oldPosition_.x, oldPosition_.y, oldChar_, COLOR::GREEN);
	else
		console_->setChar(oldPosition_.x, oldPosition_.y, oldChar_, COLOR::BLACK);

	oldChar_ = console_->getChar(position_.x, position_.y);

	drawCharacter();
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
