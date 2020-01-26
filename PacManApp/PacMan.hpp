#ifndef PACMAN_H
#define PACMAN_H

#include <conio.h>
#include "Character.hpp"

class PacMan : public Character
{
public:
    PacMan(const PacMan&) = delete;
    PacMan& operator=(const PacMan&) = delete;
    
    static PacMan& getInstance();
    virtual void   move() override;
    virtual void   changeDirection(Direction) override;
    virtual bool   isCollisionUp() const override;
    virtual bool   isCollisionDown() const override;
    virtual bool   isCollisionLeft() const override;
    virtual bool   isCollisionRight() const override;
    void           reset();
    void           setPacManMode(PACMAN_MODE);
    PACMAN_MODE    getPacManMode();

private:
    PacMan();
    ~PacMan() = default;

    PACMAN_MODE mode_;
    ConsoleUI&  console_;
};

#endif // !PACMAN_H


