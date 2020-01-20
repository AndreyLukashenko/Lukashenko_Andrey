#include "Blinky.hpp"
#include "InitialMode.hpp"
#include "BlinkyChaseMode.hpp"
#include "ScatterMode.hpp"

Blinky::Blinky() : Ghost(BLINKY_INITIAL_POINT, Direction::LEFT, CHARACTER_COLOR::BLINKY, CHARACTER_ICON::BLINKY)
{
    changeMode(getInitialMode());
}


std::shared_ptr<Blinky> Blinky::getInstance()
{
    static std::shared_ptr<Blinky> instance_ = std::make_shared<Blinky>();

    return instance_;
}


void Blinky::reset()
{
    if (oldChar_ == FRUIT || oldChar_ == GATE)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::WHITE);
    else if (oldChar_ == PILL)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::GREEN);
    else
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::BLACK);

    position_ = oldPosition_ = BLINKY_INITIAL_POINT;
    changeDirection(Direction::LEFT);
    color_ = CHARACTER_COLOR::BLINKY;
    changeMode(getInitialMode());
    oldChar_ = SPACE;
    drawCharacter();
}


std::unique_ptr<GhostMode> Blinky::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_BLINKY_FRUIT);
}


std::unique_ptr<GhostMode> Blinky::getChaseMode() const
{
    return std::make_unique<BlinkyChaseMode>();
}


std::unique_ptr<GhostMode> Blinky::getScatterMode() const
{
    return std::make_unique<ScatterMode>(BLINKY_SCATTER_POINT);
}