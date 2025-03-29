#include "Matrix.h"



Matrix::Matrix() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			matrix[i][j] = 0.0f;
		}
	}
}

Matrix Matrix::operator+(const Matrix& _matrix) const {
	Matrix result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result(i, j) = (*this)(i, j) + _matrix(i, j);
		}
	}
	return result;
}

Matrix Matrix::operator-(const Matrix& _matrix) const {
	Matrix result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			result(i, j) = (*this)(i, j) - _matrix(i, j);
		}
	}
	return result;
}

Matrix Matrix::operator*(const Matrix& _matrix) const {
	Matrix result;
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < 4; ++k) {
				result(i, j) += (*this)(i, k) * _matrix(k, j);
			}
		}
	}
	return result;
}

void Matrix::print() const {
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}