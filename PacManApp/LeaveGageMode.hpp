#ifndef LEAVE_CAGE_MODE_H
#define LEAVE_CAGE_MODE_H

#include "GhostMode.hpp"

class LeaveGageMode : public GhostMode
{
public:
    LeaveGageMode() = default;
    LeaveGageMode(const LeaveGageMode&) = delete;
    LeaveGageMode& operator=(const LeaveGageMode&) = delete;
    ~LeaveGageMode() = default;

    virtual void targetObject() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;
};

#endif // !LEAVE_CAGE_MODE_H



