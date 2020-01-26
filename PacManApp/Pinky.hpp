#ifndef PINKY_H
#define PINKY_H

#include "Ghost.hpp"

class Pinky : public Ghost
{
public:
    Pinky(const Pinky&) = delete;
    Pinky& operator=(const Pinky&) = delete;

    static Pinky&                      getInstance();
    virtual void                       reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

private:
    Pinky();
    ~Pinky() = default;
};

#endif // !PINKY_H

