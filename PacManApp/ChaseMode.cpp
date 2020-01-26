#include "ChaseMode.h"
#include "FrightenedMode.hpp"


ChaseMode::ChaseMode()
{
    timer_.start();
}


void ChaseMode::targetObject()
{
   
}


bool ChaseMode::isPacManCollision()
{
    return true;
}


bool ChaseMode::isGateObstructionUp() const
{
    return GhostMode::isGateObstructionUp();
}


bool ChaseMode::isGateObstructionRight() const
{
    return GhostMode::isGateObstructionRight();
}


bool ChaseMode::isGateObstructionDown() const
{
    return GhostMode::isGateObstructionDown();
}


bool ChaseMode::isGateObstructionLeft() const
{
    return GhostMode::isGateObstructionLeft();
}
