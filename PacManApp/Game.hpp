#ifndef  GAME_H
#define GAME_H

#include <string>
#include <vector>

#include "ConsoleUI.hpp"
#include "Timer.hpp"
#include "PacMan.hpp"
#include "Ghost.hpp"

class Game
{
public:
	Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	~Game() = default;

	void run();

private:
	double                      speedDelay_;
	int                         lives_;
	int                         score_;
	bool                        gameOver_;
	std::shared_ptr<PacMan>     pacman_;
	std::vector<std::shared_ptr<Ghost>>         ghosts_;
	Timer                       timer_;
	Timer                       timerPacMan_;
	Timer                       timerGhost_;
	std::shared_ptr<ConsoleUI>  console_;

	void updateGameField(float deltaTime);
	void pacmanMove();
	void ghostsMove();
	void showScore() const;
	void showLives() const;
	void resetGame() const;
	void gameOver();
	void drawMaze() const;

};

#endif // ! GAME_H














