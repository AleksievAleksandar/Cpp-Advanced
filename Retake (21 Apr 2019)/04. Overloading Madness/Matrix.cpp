#include "Matrix.h"

Matrix& Matrix::operator=(const std::vector<std::vector<int>>& data)
{
	if (data.size() > this->_data.size())
	{
		this->_data.resize(data.size());
	}

	for (size_t i = 0; i < data.size(); i++)
	{
		for (size_t a = 0; a < data[i].size(); a++)
		{
			this->_data[i].push_back(data[i][a]);
		}
	}
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& other)
{
	for (size_t i = 0; i < other._data.size(); i++)
	{
		for (size_t a = 0; a < other._data[i].size(); a++)
		{
			this->_data[i][a] += other._data[i][a];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix& other)
{
	for (size_t i = 0; i < other._data.size(); i++)
	{
		for (size_t a = 0; a < other._data[i].size(); a++)
		{
			this->_data[i][a] -= other._data[i][a];
		}
	}
	return *this;
}

Matrix& Matrix::operator*=(const Matrix& other)
{
	for (size_t i = 0; i < other._data.size(); i++)
	{
		for (size_t a = 0; a < other._data[i].size(); a++)
		{
			this->_data[i][a] *= other._data[i][a];
		}
	}
	return *this;
}

Matrix& Matrix::operator/=(const Matrix& other)
{
	for (size_t i = 0; i < other._data.size(); i++)
	{
		for (size_t a = 0; a < other._data[i].size(); a++)
		{
			if (other._data[i][a] != 0)
			{
				this->_data[i][a] /= other._data[i][a];
			}
			else
			{
				this->_data[i][a] = 0;
			}
		}
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Matrix& matrix)
{
	for (size_t i = 0; i < matrix._data.size(); i++)
	{
		for (size_t a = 0; a < matrix._data[i].size(); a++)
		{
			os << matrix._data[i][a] << " ";
		}
		os << "\n";
	}
	return os;
}
