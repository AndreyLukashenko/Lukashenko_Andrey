#ifndef INKY_H
#define INKY_H

#include "Ghost.hpp"

class Inky : public Ghost
{
public:
    Inky(const Inky&) = delete;
    Inky& operator=(const Inky&) = delete;

    static Inky&                       getInstance();
    virtual void                       reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

private:
    Inky();
    ~Inky() = default;
};

#endif // !INKY_H


