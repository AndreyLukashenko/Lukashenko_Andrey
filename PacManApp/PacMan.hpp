#ifndef PACMAN_H
#define PACMAN_H

#include <conio.h>
#include "Character.hpp"

class PacMan : public Character
{
public:
	PacMan();
	PacMan(const PacMan&) = delete;
	PacMan& operator=(const PacMan&) = delete;
	~PacMan() = default;

	static std::shared_ptr<PacMan> getInstance();

	virtual void move() override;
	virtual void changeDirection(Direction) override;
	virtual bool isCollisionUp() const override;
	virtual bool isCollisionDown() const override;
	virtual bool isCollisionLeft() const override;
	virtual bool isCollisionRight() const override;
	void reset();

	void setPacManMode(PACMAN_MODE);

	int getFruitEaten();
	PACMAN_MODE getPacManMode();

private:
	int fruitEaten_;
	PACMAN_MODE mode_;
};

#endif // !PACMAN_H


