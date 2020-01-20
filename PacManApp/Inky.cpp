#include "Inky.hpp"
#include "InitialMode.hpp"
#include "PinkyChaseMode.hpp"
#include "ScatterMode.hpp"

Inky::Inky() : Ghost(INKY_INITIAL_POINT, Direction::DOWN, CHARACTER_COLOR::INKY, CHARACTER_ICON::INKY)
{
    changeMode(getInitialMode());
}


std::shared_ptr<Inky> Inky::getInstance()
{
    static std::shared_ptr<Inky> instance_ = std::make_shared<Inky>();

    return instance_;
}


void Inky::reset()
{
    if (oldChar_ == FRUIT || oldChar_ == GATE)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::WHITE);
    else if (oldChar_ == PILL)
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::GREEN);
    else
        console_->setChar(position_.x, position_.y, oldChar_, COLOR::BLACK);

    position_ = oldPosition_ = INKY_INITIAL_POINT;
    changeDirection(Direction::DOWN);
    color_ = CHARACTER_COLOR::INKY;
    changeMode(getInitialMode());
    oldChar_ = SPACE;
    drawCharacter();
}


std::unique_ptr<GhostMode> Inky::getInitialMode() const
{
    return std::make_unique<InitialMode>(LEAVE_INKY_FRUIT);
}


std::unique_ptr<GhostMode> Inky::getChaseMode() const
{
    return std::make_unique<PinkyChaseMode>();
}


std::unique_ptr<GhostMode> Inky::getScatterMode() const
{
    return std::make_unique<ScatterMode>(INKY_SCATTER_POINT);
}