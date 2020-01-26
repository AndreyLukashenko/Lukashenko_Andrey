#ifndef CHASE_MODE_H
#define CHASE_MODE_H

#include "GhostMode.hpp"
#include "PacMan.hpp"
#include "Timer.hpp"

class ChaseMode : public GhostMode
{
public:
    ChaseMode();
    ChaseMode(const ChaseMode&) = delete;
    ChaseMode& operator=(const ChaseMode&) = delete;
    ~ChaseMode() = default;

    virtual void targetObject() override;
    virtual bool isPacManCollision() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;

protected:
    Timer timer_;
};

#endif // !CHASE_MODE_H



