#ifndef CHASE_MODE_H
#define CHASE_MODE_H

#include "GhostMode.hpp"
#include "PacMan.hpp"

class ChaseMode : public GhostMode
{
public:
    ChaseMode() = default;
    ChaseMode(const ChaseMode&) = delete;
    ChaseMode& operator=(const ChaseMode&) = delete;
    ~ChaseMode() = default;

    virtual void targetObject() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;

};

#endif // !CHASE_MODE_H



