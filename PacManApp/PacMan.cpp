#include "PacMan.hpp"


PacMan::PacMan() : Character(PACMAN_INITIAL_POSITION, Direction::LEFT, CHARACTER_COLOR::PACMAN, CHARACTER_ICON::PACMAN_LEFT), 
	fruitEaten_(0), mode_(PACMAN_MODE::NORMAL)
{

}


std::shared_ptr<PacMan> PacMan::getInstance()
{
	static std::shared_ptr<PacMan> instance_ = std::make_shared<PacMan>();

    return instance_;
}


void PacMan::move()
{
	if (_kbhit()) {
		Direction btnDirection = static_cast<Direction>(_getch());
		changeDirection(btnDirection);
		console_->clearInputBuffer();
	}

	Character::move();

	console_->setChar(oldPosition_.x, oldPosition_.y, SPACE, COLOR::BLACK);
	oldChar_ = console_->getChar(position_.x, position_.y);

	if (oldChar_ == FRUIT)
		fruitEaten_++;

	drawCharacter();
}


void PacMan::changeDirection(Direction newDirection)
{
	switch (newDirection)
	{
	case Direction::UP:
		if (isCollisionUp())
		{
			direction_ = Direction::UP;
			icon_ = CHARACTER_ICON::PACMAN_UP;
		}
		break;
	case Direction::DOWN:
		if (isCollisionDown())
		{
			direction_ = Direction::DOWN;
			icon_ = CHARACTER_ICON::PACMAN_DOWN;
		}
		break;
	case Direction::LEFT:
		if (isCollisionLeft())
		{
			direction_ = Direction::LEFT;
			icon_ = CHARACTER_ICON::PACMAN_LEFT;
		}
		break;
	case Direction::RIGHT:
		if (isCollisionRight())
		{
			direction_ = Direction::RIGHT;
			icon_ = CHARACTER_ICON::PACMAN_RIGHT;
		}
		break;
	default:
		break;
	}
}


bool PacMan::isCollisionUp() const
{
	return Character::isCollisionUp() && console_->getChar(position_.x, position_.y - 1) != GATE;
}


bool PacMan::isCollisionDown() const
{
	return Character::isCollisionDown() && console_->getChar(position_.x, position_.y + 1) != GATE;
}


bool PacMan::isCollisionLeft() const
{
	return Character::isCollisionLeft() && console_->getChar(position_.x - 1, position_.y) != GATE;
}


bool PacMan::isCollisionRight() const
{
	return Character::isCollisionRight() && console_->getChar(position_.x + 1, position_.y - 1) != GATE;
}


void PacMan::reset()
{
	console_->setChar(position_.x, position_.y, oldChar_, COLOR::BLACK);
	position_ = PACMAN_INITIAL_POSITION;
	direction_ = Direction::LEFT;
	icon_ = CHARACTER_ICON::PACMAN_LEFT;
	mode_ = PACMAN_MODE::NORMAL;
	drawCharacter();
}


void PacMan::setPacManMode(PACMAN_MODE mode)
{
	mode_ = mode;
}


int PacMan::getFruitEaten()
{
	return fruitEaten_;
}


PACMAN_MODE PacMan::getPacManMode()
{
	return mode_;
}