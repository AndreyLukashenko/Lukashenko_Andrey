#ifndef CLYDE_CHASE_MODE_H
#define CLYDE_CHASE_MODE_H

#include "ChaseMode.h"

class ClydeChaseMode : public ChaseMode
{
public:
    ClydeChaseMode() = default;
    ClydeChaseMode(const ClydeChaseMode&) = delete;
    ClydeChaseMode& operator=(const ClydeChaseMode&) = delete;
    ~ClydeChaseMode() = default;

    virtual void targetObject() override;
};

#endif // !CLYDE_CHASE_MODE_H



