#ifndef LEAVE_CAGE_MODE_H
#define LEAVE_CAGE_MODE_H

#include "GhostMode.hpp"

class LeaveCageMode : public GhostMode
{
public:
    LeaveCageMode() = default;
    LeaveCageMode(const LeaveCageMode&) = delete;
    LeaveCageMode& operator=(const LeaveCageMode&) = delete;
    ~LeaveCageMode() = default;

    virtual void targetObject() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;
};

#endif // !LEAVE_CAGE_MODE_H



