#include "Game.hpp"

Game::Game() : lives_(LIVES), score_(0), speedDelay_(0), gameOver_(false), pacman_(nullptr), console_(nullptr)
{
	pacman_ = PacMan::getInstance();
	console_ = ConsoleUI::getInstance();
}


void Game::run() 
{
	int deltaTime = 0;
	drawMaze();

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

	if (speedDelay_ > GAME_SPEED) {
		speedDelay_ = 0;
		pacmanMove();
		ghostsMove();
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
	}
	


	

	/*CoordinatesXY position = pacman_->getPosition();
	if (console_->getChar(position.x, position.y) == FRUIT)
	{
		score_ += 10;
	}*/
	/*else if (console_->getChar(position.x, position.y) == PILL)
	{
		score_ += 50;
		pacman_->setPacManMode(PACMAN_MODE::GODMODE);
		timerPacMan_.start();
	}*/
}


void Game::ghostsMove()
{
	/*for (Ghost* ghost : ghosts_)
	{
		if (ghost != nullptr)
		{
			ghost->move();
		}
	}*/
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


void Game::resetGame() const 
{
	/*pacman_->setInitialPosition(pacman_->getInitialPosition());
	pacman_->setDirection(pacman_->getInitialDirection());
	for (Ghost* ghost : ghosts_) {
		if (ghost != nullptr)
			ghost->reset();
	}*/
}


void Game::gameOver() 
{
	if (lives_ == 0) {
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
			default:
				console_->setChar(x, y, maze[y][x], COLOR::WHITE);
				break;
			}
		}
	}

}