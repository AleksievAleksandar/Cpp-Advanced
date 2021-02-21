#include "Snake.h"

#include <cstdlib>

bool hitObstacles(const Point& newPositionOfTheSnakeHead, const std::vector<Point>& obstacles)
{
	for (size_t i = 0; i < obstacles.size(); i++)
	{
		if (obstacles[i] == newPositionOfTheSnakeHead)
		{
			return true;
		}
	}
	return false;
}

bool hitPowerUps(Point& newPositionOfTheSnakeHead, std::vector<Point>& powerUps, std::deque<Point>& _snakeNodes)
{
	for (size_t i = 0; i < powerUps.size(); i++)
	{
		if (powerUps[i] == newPositionOfTheSnakeHead)
		{
			auto itr = powerUps.begin() + i;
			powerUps.erase(itr);

			return true;
		}
	}
	return false;
}

bool eatMySelf(const Point& newPositionOfTheSnakeHead, const std::deque<Point>& _snakeNodes)
{
	for (size_t i = 0; i < _snakeNodes.size(); i++)
	{
		if (newPositionOfTheSnakeHead == _snakeNodes[i])
		{
			return true;
		}
	}
	return false;
}

bool outOfBounds(const Point& newPosition, const Point& border)
{
	return newPosition.col < 0 || newPosition.row < 0 || newPosition.col >= border.col || newPosition.row >= border.row;
}

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos):
	_FIELD_ROWS(fieldRows),
	_FIELD_COLS(fieldCols),
	_currPos(startPos)
{
	this->_snakeNodes.push_back(startPos);
}

Snake::~Snake()
{
}

StatusCode Snake::move(const Direction dir, const std::vector<Point>& obstacles, std::vector<Point>& powerUps)
{
	switch (dir)
	{
	case Direction::UP:
		this->_currPos.row--;
		break;

	case Direction::DOWN:
		this->_currPos.row++;
		break;

	case Direction::LEFT:
		this->_currPos.col--;
		break;

	case Direction::RIGHT:
		this->_currPos.col++;
		break;

	default:
		break;
	}

	if (hitObstacles(this->_currPos, obstacles) || eatMySelf(this->_currPos, this->getSnakeNodes()) || 
		outOfBounds(this->_currPos, Point(this->_FIELD_COLS, this->_FIELD_ROWS)))
	{
		return StatusCode::SNAKE_DEAD;
	}

	this->_snakeNodes.emplace_front(this->_currPos);

	if (hitPowerUps(this->_currPos, powerUps, this->getSnakeNodes()))
	{
		return StatusCode::SNAKE_GROWING;
	}

	this->_snakeNodes.pop_back();
	return StatusCode::SNAKE_MOVING;
}

std::deque<Point>& Snake::getSnakeNodes()
{
	return this->_snakeNodes;
}
