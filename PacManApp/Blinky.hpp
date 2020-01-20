#ifndef BLINKY_H
#define BLINKY_H

#include "Ghost.hpp"

class Blinky : public Ghost
{
public:
    Blinky();
    Blinky(const Blinky&) = delete;
    Blinky& operator=(const Blinky&) = delete;
    ~Blinky() = default;

    static std::shared_ptr<Blinky> getInstance();

    virtual void reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

};

#endif // !BLINKY_H



