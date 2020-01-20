#ifndef ENTER_CAGE_POINT_H
#define ENTER_CAGE_POINT_H

#include "GhostMode.hpp"

class EnterCageMode : public GhostMode
{
public:
    EnterCageMode() = default;
    EnterCageMode(const EnterCageMode&) = delete;
    EnterCageMode& operator=(const EnterCageMode&) = delete;
    ~EnterCageMode() = default;

    virtual void targetObject() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;
};

#endif // !ENTER_CAGE_POINT_H


