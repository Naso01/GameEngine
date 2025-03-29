#include "GameController.h"

#include "Matrix.h"

using namespace glm;



int main() {
	
    //initialize and printing
    cout << "--------Printing--------" << endl;
    Matrix matrixA;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrixA(i, j) = i*2 +1;
        }
    }
    cout << "Using Class Matrix" << endl;
    cout << "Matrix A" << endl;
    matrixA.print();
    
    Matrix matrixB;

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            matrixB(i, j) = (i+1) * 2;
        }
    }
    cout << "Matrix B" << endl;
    matrixB.print();

    cout << "Using GLM:" << endl;
    glm::mat4 matrix1 = {
        {1, 1, 1, 1},
        {3, 3, 3, 3},
        {5, 5, 5, 5},
        {7, 7, 7, 7}
    };
    cout << "glm Matrix 1" << endl;
    cout << to_string(matrix1) << endl;

    glm::mat4 matrix2 = {
        {2, 2, 2, 2},
        {4, 4, 4, 4},
        {6, 6, 6, 6},
        {8, 8, 8, 8}
    };
    cout << "glm Matrix 2" << endl;
    cout << to_string(matrix2) << endl;


    //addition
    cout << "--------Addition--------" << endl;
    cout << "Using Class Matrix" << endl;
    cout << "MatrixA + MatrixB:" << endl;
    (matrixA + matrixB).print();

    cout << "Using GLM:" << endl;
    cout << "Matrix1 + Matrix2:" << endl;
    cout << to_string(matrix1 + matrix2) << endl;
    
    //subtraction
    cout << "--------Subtraction--------" << endl;
    cout << "Using Class Matrix" << endl;
    cout << "MatrixA - MatrixB:" << endl;
    (matrixA - matrixB).print();

    cout << "Using GLM:" << endl;
    cout << "Matrix1 - Matrix2:" << endl;
    cout << to_string(matrix1 - matrix2) << endl;

    //multiplication
    cout << "--------Multiplication--------" << endl;
    cout << "Using Class Matrix" << endl;
    cout << "MatrixA * MatrixB:" << endl;
    (matrixA * matrixB).print();

    cout << "Using GLM:" << endl;
    cout << "Matrix1 * Matrix2:" << endl;
    cout << to_string(matrix2 * matrix1) << endl;
    

    

    

    

	return 0;
}

