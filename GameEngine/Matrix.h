#ifndef MATRIX_H
#define MATRIX_H

#include "StandardIncludes.h"


class Matrix {

public:
	float matrix[4][4];

	//constructor/destructors
	Matrix();
	virtual ~Matrix(){}

	void print() const;

	float& operator()(int row, int col) {
		return matrix[row][col];
	}

	const float& operator()(int row, int col) const {
		return matrix[row][col];
	}


	Matrix operator+ (const Matrix& m) const;
	Matrix operator- (const Matrix& m) const;
	Matrix operator* (const Matrix& m) const;
};





#endif // !MATRIX_H