#ifndef GHOST_H
#define GHOST_H

#include "Character.hpp"


class GhostMode;

class Ghost : public Character
{
public:
    Ghost() = delete;
    Ghost(CoordinatesXY, Direction, CHARACTER_COLOR, CHARACTER_ICON);
    Ghost(const Ghost&) = delete;
    Ghost& operator=(const Ghost&) = delete;
    ~Ghost() = default;

    void changeMode(std::unique_ptr<GhostMode> mode);

    void targetObject();
    virtual void move() override;
    virtual void changeDirection(Direction) override;
    virtual bool isCollisionUp() const override;
    virtual bool isCollisionDown() const override;
    virtual bool isCollisionLeft() const override;
    virtual bool isCollisionRight() const override;
    virtual void reset() = 0;

    void setPreviousMode(std::unique_ptr<GhostMode> previousMode);

    CHARACTER_COLOR getInitialColor() const;
    Direction getDirectionOpposite() const;
    std::unique_ptr<GhostMode> getPreviousMode();

    virtual std::unique_ptr<GhostMode> getInitialMode() const = 0;
    std::unique_ptr<GhostMode> getLeaveCageMode() const;
    virtual std::unique_ptr<GhostMode> getChaseMode() const = 0;
    virtual std::unique_ptr<GhostMode> getScatterMode() const = 0;
    std::unique_ptr<GhostMode> getFrightenedMode() const;
    std::unique_ptr<GhostMode> getEnterCageMode() const;

private:
    CHARACTER_COLOR initialColor_;
    Direction directionOpposite_;
    std::unique_ptr<GhostMode> mode_;
    std::unique_ptr<GhostMode> previousMode_;
};

#endif // !GHOST_H



