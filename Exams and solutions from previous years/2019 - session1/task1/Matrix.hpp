#pragma once

template <typename T>
class Matrix {
	unsigned int x;
	unsigned int y;
	T** matrix;

	void copyMatrix(const Matrix&);
	void deleteAll();

public:
	Matrix();
	Matrix(unsigned int x, unsigned int y);
	Matrix(const Matrix&);
	Matrix& operator=(const Matrix&);
	~Matrix();

	void setAt(unsigned int x, unsigned int y, T element);
	T getAt(unsigned int x, unsigned int y);
	void transpose();
};

template<typename T>
void Matrix<T>::copyMatrix(const Matrix& other)
{
	x = other.x;
	y = other.y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			matrix[i][j] = other.matrix[i][j];
		}
	}
}

template<typename T>
void Matrix<T>::deleteAll()
{
	for (int i = 0; i < x; i++) {
		delete[] matrix[i];
	}
	delete[]matrix;
}

template<typename T>
Matrix<T>::Matrix()
	:x(2), y(2)
{
	matrix = new T * [2];
	for (int i = 0; i < 2; i++) {
		matrix[i] = new T[2];
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			matrix[i][j] = 0;
		}
	}
}

template<typename T>
Matrix<T>::Matrix(unsigned int x, unsigned int y)
	:x(x), y(y)
{
	matrix = new T * [x];
	for (int i = 0; i < x; i++) {
		matrix[i] = new T[y];
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			matrix[i][j] = 0;
		}
	}

}

template<typename T>
Matrix<T>::Matrix(const Matrix& rhs)
{
	copyMatrix(rhs);
}

template<typename T>
Matrix<T>& Matrix<T>::operator= (const Matrix& rhs)
{
	if (&rhs != this) {
		deleteAll();
		copyMatrix(rhs);
	}
	return *this;
}

template<typename T>
Matrix<T>::~Matrix()
{
	deleteAll();
}

template<typename T>
void Matrix<T>::setAt(unsigned int x, unsigned int y, T element)
{
	matrix[x - 1][y - 1] = element;
}

template<typename T>
T Matrix<T>::getAt(unsigned int x, unsigned int y)
{
	return matrix[x - 1][y - 1];
}

template<typename T>
 void Matrix<T>::transpose()
{
	 for (int i = 0; i < x; i++) {
		 for (int j = 0; j < y; j++) {
			 matrix[i][j] = matrix[j][i];
		 }
	 }
}



