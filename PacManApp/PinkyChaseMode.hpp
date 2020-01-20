#ifndef PINKY_CHASE_MODE_H
#define PINKY_CHASE_MODE_H

#include "ChaseMode.h"

class PinkyChaseMode : public ChaseMode
{
public:
    PinkyChaseMode() = default;
    PinkyChaseMode(const PinkyChaseMode&) = delete;
    PinkyChaseMode& operator=(const PinkyChaseMode&) = delete;
    ~PinkyChaseMode() = default;

    virtual void targetObject() override;
};

#endif // !PINKY_CHASE_MODE_H


