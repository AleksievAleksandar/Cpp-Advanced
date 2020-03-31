#include "Snake.h"

Snake::Snake(const int fieldRows, const int fieldCols, const Point& startPos) :
	_FIELD_ROWS(fieldRows), _FIELD_COLS(fieldCols), _currPos(startPos)
{
	this->_snakeNodes.push_back(this->_currPos);
	//this->_snakeNodes.push_back(Point(7, 6));
	//this->_snakeNodes.push_back(Point(8, 6));
	//this->_snakeNodes.push_back(Point(9, 6));
}

Snake::~Snake()
{
}


StatusCode Snake::move(const Direction dir, const std::vector<Point>& obstacles, std::vector<Point>& powerUps)
{
	StatusCode temp = StatusCode::SNAKE_MOVING;
	bool snakeAlive = true;

	switch (dir)
	{
	case Direction::UP:
	{
		if (this->_currPos.row > 0)
		{
			int prevRow = this->_currPos.row;
			int prevCol = this->_currPos.col;

			this->_currPos.row--;
			temp = StatusCode::SNAKE_MOVING;

			//eat myself
			if (this->_snakeNodes.size() > 2)
			{
				for (int i = 0; i < this->_snakeNodes.size(); i++)
				{
					if (this->_currPos.col == this->_snakeNodes[i].col && this->_currPos.row == this->_snakeNodes[i].row)
					{
						snakeAlive = false;
						temp = StatusCode::SNAKE_DEAD;
						break;
					}
				}
			}

			if (snakeAlive)
			{
				for (int i = 0; i < powerUps.size(); i++) //increase body
				{
					if (powerUps[i].col == this->_currPos.col && powerUps[i].row == this->_currPos.row)
					{
						this->_snakeNodes.push_back(Point(this->_currPos.row, this->_currPos.col));
						powerUps.erase(powerUps.begin() + i);
						temp = StatusCode::SNAKE_GROWING;
						break;
					}
				}

				for (int i = 0; i < obstacles.size(); i++) //hit obstacles
				{
					if (obstacles[i].col == this->_currPos.col && obstacles[i].row == this->_currPos.row)
					{
						temp = StatusCode::SNAKE_DEAD;
						snakeAlive = false;
						break;
					}
				}

				if (snakeAlive) //move snake body in accordance of the head of the snake
				{
					for (int i = 0; i < this->_snakeNodes.size(); i++)
					{
						if (i == 0)
						{
							this->_snakeNodes[i].row = this->_currPos.row;
						}
						else
						{
							int tempR = this->_snakeNodes[i].row;
							int tempC = this->_snakeNodes[i].col;

							this->_snakeNodes[i].row = prevRow;
							this->_snakeNodes[i].col = prevCol;

							prevRow = tempR;
							prevCol = tempC;
						}
					}
				}
			}
		}
		else
		{
			temp = StatusCode::SNAKE_DEAD;
		}
		break;
	}
	case Direction::DOWN:
	{
		if (this->_currPos.row < this->_FIELD_ROWS - 1)
		{
			int prevRow = this->_currPos.row;
			int prevCol = this->_currPos.col;

			this->_currPos.row++;
			temp = StatusCode::SNAKE_MOVING;

			//eat myself
			if (this->_snakeNodes.size() > 2)
			{
				for (int i = 0; i < this->_snakeNodes.size(); i++)
				{
					if (this->_currPos.col == this->_snakeNodes[i].col && this->_currPos.row == this->_snakeNodes[i].row)
					{
						snakeAlive = false;
						temp = StatusCode::SNAKE_DEAD;
						break;
					}
				}
			}

			if (snakeAlive)
			{
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i].col == this->_currPos.col && powerUps[i].row == this->_currPos.row)
					{
						this->_snakeNodes.push_back(Point(this->_currPos.row, this->_currPos.col));
						powerUps.erase(powerUps.begin() + i);
						temp = StatusCode::SNAKE_GROWING;
						break;
					}
				}

				for (int i = 0; i < obstacles.size(); i++)
				{
					if (obstacles[i].col == this->_currPos.col && obstacles[i].row == this->_currPos.row)
					{
						temp = StatusCode::SNAKE_DEAD;
						snakeAlive = false;
						break;
					}
				}

				if (snakeAlive)
				{
					for (int i = 0; i < this->_snakeNodes.size(); i++)
					{
						if (i == 0)
						{
							this->_snakeNodes[i].row = this->_currPos.row;
						}
						else
						{
							int tempR = this->_snakeNodes[i].row;
							int tempC = this->_snakeNodes[i].col;

							this->_snakeNodes[i].row = prevRow;
							this->_snakeNodes[i].col = prevCol;

							prevRow = tempR;
							prevCol = tempC;
						}
					}
				}
			}

		}
		else
		{
			temp = StatusCode::SNAKE_DEAD;
		}
		break;
	}
	case Direction::LEFT:
	{
		if (this->_currPos.col > 0)
		{
			int prevRow = this->_currPos.row;
			int prevCol = this->_currPos.col;

			this->_currPos.col--;
			temp = StatusCode::SNAKE_MOVING;

			//eat myself
			if (this->_snakeNodes.size() > 2)
			{
				for (int i = 0; i < this->_snakeNodes.size(); i++)
				{
					if (this->_currPos.col == this->_snakeNodes[i].col && this->_currPos.row == this->_snakeNodes[i].row)
					{
						snakeAlive = false;
						temp = StatusCode::SNAKE_DEAD;
						break;
					}
				}
			}

			if (snakeAlive)
			{
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i].col == this->_currPos.col && powerUps[i].row == this->_currPos.row)
					{
						this->_snakeNodes.push_back(Point(this->_currPos.row, this->_currPos.col));
						powerUps.erase(powerUps.begin() + i);
						temp = StatusCode::SNAKE_GROWING;
						break;
					}
				}

				for (int i = 0; i < obstacles.size(); i++)
				{
					if (obstacles[i].col == this->_currPos.col && obstacles[i].row == this->_currPos.row)
					{
						temp = StatusCode::SNAKE_DEAD;
						snakeAlive = false;
						break;
					}
				}

				if (snakeAlive)
				{
					for (int i = 0; i < this->_snakeNodes.size(); i++)
					{
						if (i == 0)
						{
							this->_snakeNodes[i].col = this->_currPos.col;
						}
						else
						{
							int tempR = this->_snakeNodes[i].row;
							int tempC = this->_snakeNodes[i].col;

							this->_snakeNodes[i].row = prevRow;
							this->_snakeNodes[i].col = prevCol;

							prevRow = tempR;
							prevCol = tempC;
						}
					}
				}
			}

		}
		else
		{
			temp = StatusCode::SNAKE_DEAD;
		}
		break;
	}
	case Direction::RIGHT:
	{
		if (this->_currPos.col < this->_FIELD_COLS - 1)
		{
			int prevRow = this->_currPos.row;
			int prevCol = this->_currPos.col;

			this->_currPos.col++;
			temp = StatusCode::SNAKE_MOVING;

			//eat myself
			if (this->_snakeNodes.size() > 2)
			{
				for (int i = 0; i < this->_snakeNodes.size(); i++)
				{
					if (this->_currPos.col == this->_snakeNodes[i].col && this->_currPos.row == this->_snakeNodes[i].row)
					{
						snakeAlive = false;
						temp = StatusCode::SNAKE_DEAD;
						break;
					}
				}
			}

			if (snakeAlive)
			{
				for (int i = 0; i < powerUps.size(); i++)
				{
					if (powerUps[i].col == this->_currPos.col && powerUps[i].row == this->_currPos.row)
					{
						this->_snakeNodes.push_back(Point(this->_currPos.row, this->_currPos.col));
						powerUps.erase(powerUps.begin() + i);
						temp = StatusCode::SNAKE_GROWING;
						break;
					}
				}

				for (int i = 0; i < obstacles.size(); i++)
				{
					if (obstacles[i].col == this->_currPos.col && obstacles[i].row == this->_currPos.row)
					{
						temp = StatusCode::SNAKE_DEAD;
						snakeAlive = false;
						break;
					}
				}

				if (snakeAlive)
				{
					for (int i = 0; i < this->_snakeNodes.size(); i++)
					{
						if (i == 0)
						{
							this->_snakeNodes[i].col = this->_currPos.col;
						}
						else
						{
							int tempR = this->_snakeNodes[i].row;
							int tempC = this->_snakeNodes[i].col;

							this->_snakeNodes[i].row = prevRow;
							this->_snakeNodes[i].col = prevCol;

							prevRow = tempR;
							prevCol = tempC;
						}
					}
				}
			}

		}
		else
		{
			temp = StatusCode::SNAKE_DEAD;
		}
		break;
	}

	default:
		break;
	}

	return temp;
}

std::deque<Point>& Snake::getSnakeNodes()
{
	// TODO: insert return statement here

	return this->_snakeNodes;
}
