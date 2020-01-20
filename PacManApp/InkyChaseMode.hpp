#ifndef INKY_CHASE_MODE_H
#define INKY_CHASE_MODE_H

#include "ChaseMode.h"

class InkyChaseMode : public ChaseMode
{
public:
    InkyChaseMode() = default;
    InkyChaseMode(const InkyChaseMode&) = delete;
    InkyChaseMode& operator=(const InkyChaseMode&) = delete;
    ~InkyChaseMode() = default;

    virtual void targetObject() override;
};
#endif // !INKY_CHASE_MODE_H



