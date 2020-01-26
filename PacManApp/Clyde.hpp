#ifndef CLYDE_H
#define CLYDE_H

#include "Ghost.hpp"

class Clyde : public Ghost
{
public:
    Clyde(const Clyde&) = delete;
    Clyde& operator=(const Clyde&) = delete;

    static Clyde&                      getInstance();
    virtual void                       reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

private:
    Clyde();
    ~Clyde() = default;
};

#endif // !CLYDE_H


