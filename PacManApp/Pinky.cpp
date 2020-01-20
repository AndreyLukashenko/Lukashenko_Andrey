#include "Pinky.hpp"
#include "InitialMode.hpp"
#include "PinkyChaseMode.hpp"
#include "ScatterMode.hpp"

Pinky::Pinky() : Ghost(PINKY_INITIAL_POINT, Direction::UP, CHARACTER_COLOR::PINKY, CHARACTER_ICON::PINKY)
{
    changeMode(getInitialMode());
}


std::shared_ptr<Pinky> Pinky::getInstance()
{
    static std::shared_ptr<Pinky> instance_ = std::make_shared<Pinky>();

    return instance_;
}


void Pinky::reset()
{
    if (oldChar_ == FRUIT || oldChar_ == GATE)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::WHITE);
    else if (oldChar_ == PILL)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::GREEN);
    else
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::BLACK);

    position_ = oldPosition_ = PINKY_INITIAL_POINT;
    changeDirection(Direction::UP);
    color_ = CHARACTER_COLOR::PINKY;
    changeMode(getInitialMode());
    oldChar_ = SPACE;
    drawCharacter();
}


std::unique_ptr<GhostMode> Pinky::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_PINKY_FRUIT);
}


std::unique_ptr<GhostMode> Pinky::getChaseMode() const
{
    return std::make_unique<PinkyChaseMode>();
}


std::unique_ptr<GhostMode> Pinky::getScatterMode() const
{
    return std::make_unique<ScatterMode>(PINKY_SCATTER_POINT);
}
