#ifndef INKY_H
#define INKY_H

#include "Ghost.hpp"

class Inky : public Ghost
{
public:
    Inky();
    Inky(const Inky&) = delete;
    Inky& operator=(const Inky&) = delete;
    ~Inky() = default;

    static std::shared_ptr<Inky> getInstance();

    virtual void reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

};

#endif // !INKY_H


