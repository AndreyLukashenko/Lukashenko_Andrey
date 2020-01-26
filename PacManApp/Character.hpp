#ifndef CHARACTER_H
#define CHARACTER_H

#include "Constants.hpp"
#include "ConsoleUI.hpp"

class Character
{
public:
    Character() = delete;
    Character(CoordinatesXY, Direction, CHARACTER_COLOR, CHARACTER_ICON);
    Character(const Character&) = delete;
    Character& operator=(const Character&) = delete;
    virtual ~Character() = default;

    virtual void  move() = 0;
    virtual void  changeDirection(Direction) = 0;
    virtual bool  isCollisionUp() const = 0;
    virtual bool  isCollisionDown() const = 0;
    virtual bool  isCollisionLeft() const = 0;
    virtual bool  isCollisionRight() const = 0;
    void          drawCharacter();
    void          setColor(CHARACTER_COLOR);
    CoordinatesXY getPosition() const;
    Direction     getDirection() const;

protected:
    CoordinatesXY   position_;
    CoordinatesXY	oldPosition_;
    Direction       direction_;
    CHARACTER_COLOR color_;
    CHARACTER_ICON  icon_;
    ConsoleUI&      console_;
};

#endif // !CHARACTER_H



