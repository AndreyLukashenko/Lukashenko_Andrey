#include "Character.hpp"

Character::Character(CoordinatesXY position, Direction direction, CHARACTER_COLOR color, CHARACTER_ICON icon) :
    position_(position), direction_(direction), color_(color), icon_(icon), console_(ConsoleUI::getInstance())
{
    oldPosition_ = position;
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

    if (position_.x == 0)
        position_.x = FIELD_WIDTH - 1;
    else if (position_.x == FIELD_WIDTH - 1)
        position_.x = 0;
}


bool Character::isCollisionUp() const
{
    return console_.getChar(position_.x, position_.y - 1) != OBSTRUCTION;
}


bool Character::isCollisionDown() const
{
    return console_.getChar(position_.x, position_.y + 1) != OBSTRUCTION;
}


bool Character::isCollisionLeft() const
{
    int offset = 1;
    if (position_.x == 0)
        offset = 0;
    return console_.getChar(position_.x - offset, position_.y) != OBSTRUCTION;
}


bool Character::isCollisionRight() const
{
    int offset = 1;
    if (position_.x == FIELD_WIDTH - 1)
        offset = 0;
    return console_.getChar(position_.x + offset, position_.y) != OBSTRUCTION;
}


void Character::drawCharacter()
{
    console_.setChar(position_.x, position_.y, static_cast<wchar_t>(icon_), static_cast<COLOR>(color_));
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