#include "Character.hpp"

Character::Character(CoordinatesXY position, Direction direction, CHARACTER_COLOR color, CHARACTER_ICON icon) :
    position_(position), direction_(direction), color_(color), icon_(icon), oldChar_(SPACE), console_(nullptr)
{
	oldPosition_ = position;
	console_ = ConsoleUI::getInstance();
}


void Character::move()
{
	oldPosition_ = position_;

	switch (direction_)
	{
		case Direction::UP:
		if (isCollisionUp())
			--position_.y;
		break;
	case Direction::DOWN:
		if (isCollisionDown())
			++position_.y;
		break;
	case Direction::LEFT:
		if (isCollisionLeft())
			--position_.x;
		break;
	case Direction::RIGHT:
		if (isCollisionRight())
			++position_.x;
		break;
	default:
		break;
	}
}


bool Character::isCollisionUp() const
{
	return console_->getChar(position_.x, position_.y - 1) != OBSTRUCTION;
}


bool Character::isCollisionDown() const
{
	return console_->getChar(position_.x, position_.y + 1) != OBSTRUCTION;
}


bool Character::isCollisionLeft() const
{
	return console_->getChar(position_.x - 1, position_.y) != OBSTRUCTION;
}


bool Character::isCollisionRight() const
{
	return console_->getChar(position_.x + 1, position_.y) != OBSTRUCTION;
}


void Character::drawCharacter()
{
	if (position_.x == 0)
		position_.x = FIELD_WIDTH - 1;
	else if (position_.x == FIELD_WIDTH - 1)
		position_.x = 0;

	console_->setChar(position_.x, position_.y, static_cast<wchar_t>(icon_), static_cast<COLOR>(color_));
}


void Character::setColor(CHARACTER_COLOR color)
{
	color_ = color;
}


Direction Character::getDirection() const
{
	return direction_;
}


CoordinatesXY Character::getPosition() const
{
	return position_;
}


wchar_t Character::getOldChar() const
{
	return oldChar_;
}