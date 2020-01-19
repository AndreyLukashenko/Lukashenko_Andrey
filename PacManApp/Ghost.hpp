#ifndef GHOST_H
#define GHOST_H

#include "Character.hpp"

class GhostMode;

class Ghost : public Character, public std::enable_shared_from_this<Ghost>
{
public:
    Ghost() = delete;
    Ghost(CoordinatesXY, Direction, CHARACTER_COLOR, CHARACTER_ICON, int fruitLeave, CoordinatesXY);
    Ghost(const Ghost&) = delete;
    Ghost& operator=(const Ghost&) = delete;
    ~Ghost() = default;

    void changeMode(GhostMode* mode);

    void targetObject();
    virtual void move() override;
    virtual void changeDirection(Direction) override;
    virtual bool isCollisionUp() const override;
    virtual bool isCollisionDown() const override;
    virtual bool isCollisionLeft() const override;
    virtual bool isCollisionRight() const override;

    void setPreviousMode(GhostMode* previousMode);

    CHARACTER_COLOR getInitialColor();
    int getFruitLeaveCount();
    CoordinatesXY getScatterPoint();
    Direction getdirectionOpposite();
    GhostMode* getPreviousMode();

private:
    CHARACTER_COLOR initialColor_;
    int fruitLeaveCount_;
    CoordinatesXY scatterPoint_;
    Direction directionOpposite_;
    std::unique_ptr<GhostMode> mode_;
    std::unique_ptr<GhostMode> previousMode_;
};

#endif // !GHOST_H



