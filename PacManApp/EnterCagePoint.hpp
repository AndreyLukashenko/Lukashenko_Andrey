#ifndef ENTER_CAGE_POINT_H
#define ENTER_CAGE_POINT_H

#include "GhostMode.hpp"

class EnterCagePoint : GhostMode
{
public:
    EnterCagePoint() = default;
    EnterCagePoint(const EnterCagePoint&) = delete;
    EnterCagePoint& operator=(const EnterCagePoint&) = delete;
    ~EnterCagePoint() = default;

    virtual void targetObject() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;
};

#endif // !ENTER_CAGE_POINT_H


