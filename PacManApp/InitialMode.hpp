#ifndef INITIAL_MODE_H
#define INITIAL_MODE_H

#include "GhostMode.hpp"
#include "PacMan.hpp"
#include "Game.hpp"

class InitialMode : public GhostMode
{
public:
    InitialMode() = delete;
    InitialMode(int fruitLeave);
    InitialMode(const InitialMode&) = delete;
    InitialMode& operator=(const InitialMode&) = delete;
    ~InitialMode() = default;

    virtual void targetObject() override;
    virtual bool isPacManCollision() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;
private:
    int fruitLeave_;
};
#endif // !INITIAL_MODE_H



