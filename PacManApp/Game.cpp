#include "Game.hpp"
#include "GhostMode.hpp"

Game::Game() : lives_(LIVES), score_(0), speedDelay_(0), gameOver_(false), pacman_(nullptr), console_(nullptr)
{
	pacman_ = PacMan::getInstance();
	console_ = ConsoleUI::getInstance();
	drawMaze();
	std::shared_ptr<Ghost> blinky = Blinky::getInstance();
	ghosts_.push_back(blinky);

	std::shared_ptr<Ghost> pinky = Pinky::getInstance();
	ghosts_.push_back(pinky);

	std::shared_ptr<Ghost> inky = Inky::getInstance();
	ghosts_.push_back(inky);

	std::shared_ptr<Ghost> clyde = Clyde::getInstance();
	ghosts_.push_back(clyde);

	timerPauseStart_.start();
}


void Game::run() 
{
	int deltaTime = 0;
	
	while (true) {
		timer_.start();
		if (!gameOver_)
			updateGameField(static_cast<float>(deltaTime) / 1000.0f);
		console_->render();
		Sleep(1);

		while (true)
		{
			deltaTime = timer_.elapsedMilliseconds();
			if (deltaTime > 20)
				break;
		}
	}
}


void Game::updateGameField(float deltaTime)
{
	speedDelay_ += deltaTime;

	if (timerPauseStart_.elapsedSeconds() > GAME_START_DELAY)
	{
		if (speedDelay_ > GAME_SPEED) {
			speedDelay_ = 0;
			pacmanMove();
			ghostsMove();
		}
	}
	
	showScore();
	showLives();
	gameOver();
}


void Game::pacmanMove()
{
	if (pacman_ != nullptr)
	{
		
		if (pacman_->getPacManMode() == PACMAN_MODE::GODMODE)
		{
			if (timerPacMan_.elapsedSeconds() > TIMER_PACMAN_GODMODE)
			{
				pacman_->setPacManMode(PACMAN_MODE::NORMAL);
			}
		}
		
		if (pacman_->getOldChar() == FRUIT)
		{
			score_ += 10;
		}
		else if (pacman_->getOldChar() == PILL)
		{
			score_ += 50;
			pacman_->setPacManMode(PACMAN_MODE::GODMODE);
			timerPacMan_.start();
		}

		pacman_->move();
		checkForDeath();
	}
	
}


void Game::ghostsMove()
{
	for (std::shared_ptr<Ghost> ghost : ghosts_)
	{
		if (ghost != nullptr)
		{
			ghost->move();
			checkForDeath();
		}
	}
}


void Game::showScore() const 
{
	std::string score = std::to_string(score_);
	for (int i = 0; i < score.length(); ++i) {
		console_->setChar(8 + i, 32, score[i], COLOR::RED);
	}
}


void Game::showLives() const 
{
	std::string lives = std::to_string(lives_);
	console_->setChar(25, 32, lives[0], COLOR::RED);
}


void Game::checkForDeath()
{
	for (std::shared_ptr<Ghost> ghost : ghosts_)
	{
		if (ghost != nullptr)
		{
			if (pacman_->getPosition() == ghost->getPosition())
			{
				if (pacman_->getPacManMode() == PACMAN_MODE::NORMAL)
				{
					--lives_;
					if (lives_ > 0)
						resetGame();
				}
				else
				{
					ghost->setColor(CHARACTER_COLOR::ENTERMODE);
					ghost->changeMode(ghost->getEnterCageMode());
				}
			}
		}
	}
}


void Game::resetGame() 
{
	pacman_->reset();
	for (std::shared_ptr<Ghost> ghost : ghosts_) {
		if (ghost != nullptr)
			ghost->reset();
	}
	timerPauseStart_.start();
}


void Game::gameOver() 
{
	if (lives_ <= 0) {
		gameOver_ = true;
		std::string message = "You lose";
		for (int i = 0; i < message.length(); ++i) {
			console_->setChar(10 + i, 17, message[i], COLOR::RED);
		}
	}
	else if (pacman_->getFruitEaten() == FRUIT_COUNT) {
		gameOver_ = true;
		std::string message = "You win";
		for (int i = 0; i < message.length(); ++i) {
			console_->setChar(10 + i, 17, message[i], COLOR::LIGHT_GREEN);
		}
	}

}


void Game::drawMaze() const
{
	for (int y = 0; y < FIELD_HEIGHT; ++y) {
		for (int x = 0; x < FIELD_WIDTH; ++x) {
			switch (maze[y][x])
			{
			case FRUIT:
				console_->setChar(x, y, maze[y][x], COLOR::WHITE);
				break;
			case OBSTRUCTION:
				console_->setChar(x, y, maze[y][x], COLOR::BLUE);
				break;
			case PILL:
				console_->setChar(x, y, maze[y][x], COLOR::GREEN);
				break;
			case static_cast<char>(CHARACTER_ICON::PACMAN_LEFT):
				console_->setChar(x, y, maze[y][x], static_cast<COLOR>(CHARACTER_COLOR::PACMAN));
				break;
			case static_cast<char>(CHARACTER_ICON::BLINKY) :
				console_->setChar(x, y, maze[y][x], static_cast<COLOR>(CHARACTER_COLOR::BLINKY));
				break;
			case static_cast<char>(CHARACTER_ICON::INKY) :
				console_->setChar(x, y, maze[y][x], static_cast<COLOR>(CHARACTER_COLOR::INKY));
				break;
			case static_cast<char>(CHARACTER_ICON::PINKY) :
				console_->setChar(x, y, maze[y][x], static_cast<COLOR>(CHARACTER_COLOR::PINKY));
				break;
			case static_cast<char>(CHARACTER_ICON::CLYDE) :
				console_->setChar(x, y, maze[y][x], static_cast<COLOR>(CHARACTER_COLOR::CLYDE));
				break;
			default:
				console_->setChar(x, y, maze[y][x], COLOR::WHITE);
				break;
			}
		}
	}

}