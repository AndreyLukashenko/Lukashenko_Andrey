#ifndef SCATTER_MODE_H
#define SCATTER_MODE_H

#include "GhostMode.hpp"
#include "PacMan.hpp"

class ScatterMode : public GhostMode
{
public:
    ScatterMode() = delete;
    ScatterMode(CoordinatesXY cornerPoint);
    ScatterMode(const ScatterMode&) = delete;
    ScatterMode& operator=(const ScatterMode&) = delete;

    virtual void targetObject() override;
    virtual bool isGateObstructionUp() const override;
    virtual bool isGateObstructionRight() const override;
    virtual bool isGateObstructionDown() const override;
    virtual bool isGateObstructionLeft() const override;

private:
    CoordinatesXY cornerPoint_;
};

#endif // !SCATTER_MODE_H

