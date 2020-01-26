#ifndef BLINKY_H
#define BLINKY_H

#include "Ghost.hpp"

class Blinky : public Ghost
{
public:
    Blinky(const Blinky&) = delete;
    Blinky& operator=(const Blinky&) = delete;

    static Blinky&                     getInstance();
    virtual void                       reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

private:
    Blinky();
    ~Blinky() = default;
};

#endif // !BLINKY_H



