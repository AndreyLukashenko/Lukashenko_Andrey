#ifndef CLYDE_H
#define CLYDE_H

#include "Ghost.hpp"

class Clyde : public Ghost
{
public:
    Clyde();
    Clyde(const Clyde&) = delete;
    Clyde& operator=(const Clyde&) = delete;
    ~Clyde() = default;

    static std::shared_ptr<Clyde> getInstance();

    virtual void reset() override;
    virtual std::unique_ptr<GhostMode> getInitialMode() const override;
    virtual std::unique_ptr<GhostMode> getChaseMode() const override;
    virtual std::unique_ptr<GhostMode> getScatterMode() const override;

};

#endif // !CLYDE_H


