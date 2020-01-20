#include "Clyde.hpp"
#include "InitialMode.hpp"
#include "ClydeChaseMode.h"
#include "ScatterMode.hpp"

Clyde::Clyde() : Ghost(CLYDE_INITIAL_POINT, Direction::UP, CHARACTER_COLOR::CLYDE, CHARACTER_ICON::CLYDE)
{
    changeMode(getInitialMode());
}


std::shared_ptr<Clyde> Clyde::getInstance()
{
    static std::shared_ptr<Clyde> instance_ = std::make_shared<Clyde>();

    return instance_;
}


void Clyde::reset()
{
    if (oldChar_ == FRUIT || oldChar_ == GATE)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::WHITE);
    else if (oldChar_ == PILL)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::GREEN);
    else
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::BLACK);

    position_ = oldPosition_ = CLYDE_INITIAL_POINT;
    changeDirection(Direction::UP);
    color_ = CHARACTER_COLOR::CLYDE;
    changeMode(getInitialMode());
    oldChar_ = SPACE;
    drawCharacter();
}


std::unique_ptr<GhostMode> Clyde::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_CLYDE_FRUIT);
}


std::unique_ptr<GhostMode> Clyde::getChaseMode() const
{
    return std::make_unique<ClydeChaseMode>();
}


std::unique_ptr<GhostMode> Clyde::getScatterMode() const
{
    return std::make_unique<ScatterMode>(CLYDE_SCATTER_POINT);
}