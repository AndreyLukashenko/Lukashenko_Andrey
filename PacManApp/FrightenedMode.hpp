#ifndef FRIGHTENED_MODE_H
#define FRIGHTENED_MODE_H

#include "GhostMode.hpp"
#include "PacMan.hpp"

class FrightenedMode : public GhostMode
{
public:
    FrightenedMode() = default;
    FrightenedMode(const FrightenedMode&) = delete;
    FrightenedMode& operator=(const FrightenedMode&) = delete;
    ~FrightenedMode() = default;

    virtual void targetObject() override;
    virtual bool isPacManCollision() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;
};

#endif // !FRIGHTENED_MODE_H



