#ifndef MATRIX_H_
#define MATRIX_H_
class Matrix
{
private:
	void copy(const Matrix& other);
	void destroy();

	int rows;
	int cols;
	int** data;


public:
	Matrix(int rows, int cols);
	~Matrix();
	Matrix(const Matrix& other);

	Matrix& operator=(const Matrix& other);

	// Move
	Matrix(Matrix&& other);
	Matrix& operator=(Matrix&& other);

	int& operator()(int row, int col);  // lvalue

	Matrix operator+(const Matrix& other) const;

	Matrix operator-(const Matrix& other) const;

	Matrix operator*(const Matrix& other) const;

	bool operator==(const Matrix& other) const;

	friend Matrix transpose(const Matrix& matrix);

	friend void print(const Matrix& matrix);
};

#endif
