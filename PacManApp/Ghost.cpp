#include "Ghost.hpp"
#include "InitialMode.hpp"

Ghost::Ghost(CoordinatesXY position, Direction direction, CHARACTER_COLOR color, CHARACTER_ICON icon, int fruitLeave, CoordinatesXY scatterPoint) :
    Character(position, direction, color, icon), initialColor_(color), fruitLeaveCount_(fruitLeave), scatterPoint_(scatterPoint), 
	directionOpposite_(Direction::NONE), mode_(nullptr)
{
	changeDirection(direction);
	changeMode(new InitialMode(fruitLeave));
}


void Ghost::changeMode(GhostMode* mode)
{
	mode_.reset(mode);
	//auto test = shared_from_this();
	mode_->setGhost(this);
	mode_->targetObject();
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

void Ghost::setPreviousMode(GhostMode* previousMode)
{
	previousMode_.reset(previousMode);
}


CHARACTER_COLOR Ghost::getInitialColor()
{
	return initialColor_;
}


int Ghost::getFruitLeaveCount()
{
	return fruitLeaveCount_;
}


CoordinatesXY Ghost::getScatterPoint()
{
	return scatterPoint_;
}


Direction Ghost::getdirectionOpposite()
{
	return directionOpposite_;
}


GhostMode* Ghost::getPreviousMode()
{
	return previousMode_.get();
}