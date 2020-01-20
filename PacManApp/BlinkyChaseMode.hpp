#ifndef BLINKY_CHASE_MODE_H
#define BLINKY_CHASE_MODE_H

#include "ChaseMode.h"

class BlinkyChaseMode : public ChaseMode
{
public:
    BlinkyChaseMode() = default;
    BlinkyChaseMode(const BlinkyChaseMode&) = delete;
    BlinkyChaseMode& operator=(const BlinkyChaseMode&) = delete;
    ~BlinkyChaseMode() = default;

    virtual void targetObject() override;
};

#endif // !BLINKY_CHASE_MODE_H



