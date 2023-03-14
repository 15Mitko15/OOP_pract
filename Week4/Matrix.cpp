#include "Matrix.h"
#include <iostream>

void Matrix::copy(const Matrix& other)
{
	rows = other.rows;
	cols = other.cols;

	data = new int* [rows];
	for (size_t i = 0; i < rows; i++)
	{
		data[i] = new int[cols];
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] = other.data[i][j];;
		}
	}

}

void Matrix::destroy()
{
	for (size_t i = 0; i < rows; i++)
	{
		delete[] data[i];
	}
	delete[] data;
}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols), data(new int* [rows])
{
	for (size_t i = 0; i < rows; i++)
	{
		data[i] = new int[cols];
		for (size_t j = 0; j < cols; j++)
		{
			data[i][j] = 0;
		}
	}
}

Matrix::~Matrix()
{
	destroy();
}

Matrix::Matrix(const Matrix& other)
{
	copy(other);
}

Matrix& Matrix::operator=(const Matrix& other)
{
	if (this != &other)
	{
		destroy();
		copy(other);
	}

	return *this;
}

Matrix::Matrix(Matrix&& other)
{
	rows = other.rows;
	cols = other.cols;
	data = other.data;

	other.data = nullptr;
	other.rows = 0;
	other.cols = 0;
}

Matrix& Matrix::operator=(Matrix&& other)
{
	if (this != &other)
	{
		destroy();
		rows = other.rows;
		cols = other.cols;
		data = other.data;

		other.data = nullptr;
		other.rows = 0;
		other.cols = 0;
	}

	return *this;
}

int& Matrix::operator()(int row, int col)
{
	if (row > rows || col > cols || row < 0 || col < 0)
	{
		throw std::exception("Invalid indexes");
	}

	return data[row][col];
}

Matrix Matrix::operator+(const Matrix& other) const
{
	if (rows != other.rows || cols != other.cols)
	{
		throw std::exception("Can't sum them");
	}

	Matrix newMatrix(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newMatrix.data[i][j] = data[i][j] + other.data[i][j];
		}
	}

	return newMatrix;
}

Matrix Matrix::operator-(const Matrix& other) const
{
	if (rows != other.rows || cols != other.cols)
	{
		throw std::exception("Can't substract them");
	}

	Matrix newMatrix(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newMatrix.data[i][j] = data[i][j] + other.data[i][j];
		}
	}

	return newMatrix;
}

Matrix Matrix::operator*(const Matrix& other) const
{
	if (rows != other.rows || cols != other.cols)
	{
		throw std::exception("Can't multiply them");
	}

	Matrix newMatrix(rows, cols);
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			newMatrix.data[i][j] = data[i][j]*other.data[i][j];
		}
	}

	return newMatrix;
}

bool Matrix::operator==(const Matrix& other) const
{
	if (rows != other.rows || cols != other.cols)
	{
		return false;
	}

	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = 0; j < cols; j++)
		{
			if (data[i][j] != other.data[i][j])
			{
				return false;
			}
		}
	}
	return true;
}

Matrix transpose(const Matrix& matrix)
{
	Matrix tempMatrix(matrix.cols, matrix.rows);
	for (size_t i = 0; i < matrix.rows / 2; i++)
	{
		for (size_t j = 0; j < matrix.cols; j++)
		{
			tempMatrix.data[i][j] = matrix.data[matrix.rows - 1 - i][j];
		}
	}

	return tempMatrix;
}

void print(const Matrix& matrix)
{
	std::cout << '(' << matrix.rows << ", " << matrix.cols << ')' << std::endl;
	for (size_t i = 0; i < matrix.rows; i++)
	{
		for (size_t j = 0; j < matrix.cols; j++)
		{
			std::cout << matrix.data[i][j] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout<<std::endl;

}
