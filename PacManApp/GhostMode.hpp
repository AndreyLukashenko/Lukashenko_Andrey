#ifndef GHOST_MODE_H
#define GHOST_MODE_H

#include <memory>

#include "Ghost.hpp"
#include "DirectionMeasurement.hpp"

class GhostMode
{
public:
	GhostMode() = default;
	GhostMode(const GhostMode&) = delete;
	GhostMode& operator=(const GhostMode&) = delete;
	virtual ~GhostMode() = default;

	void setGhost(Ghost*);

	virtual void targetObject() = 0;
	virtual bool isGateObstructionUp() const = 0;
	virtual bool isGateObstructionRight() const = 0;
	virtual bool isGateObstructionDown() const = 0;
	virtual bool isGateObstructionLeft() const = 0;

protected:
	//std::weak_ptr<Ghost> ghost_;
	Ghost* ghost_;
	DirectionMeasurement directionMeasurement_;
};

#endif // !GHOST_MODE_H



