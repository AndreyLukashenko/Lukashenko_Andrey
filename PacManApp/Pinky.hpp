#ifndef PINKY_H
#define PINKY_H

#include "Ghost.hpp"

class Pinky : public Ghost
{
public:
    Pinky();
    Pinky(const Pinky&) = delete;
    Pinky& operator=(const Pinky&) = delete;
    ~Pinky() = default;

    static std::shared_ptr<Pinky> getInstance();

    virtual void reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

};

#endif // !PINKY_H

