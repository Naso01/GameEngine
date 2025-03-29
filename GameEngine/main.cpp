#include "GameController.h"

using namespace glm;



int main() {
    glm::mat4 matrix1 = {
      {1, 1, 1, 1},
      {2, 2, 2, 2},
      {3, 3, 3, 3},
      {4, 4, 4, 4}
    };

    glm::mat4 matrix2 = {
      {5, 5, 5, 5},
      {6, 6, 6, 6},
      {7, 7, 7, 7},
      {8, 8, 8, 8}
    };

    cout << "Matrix1: " << glm::to_string(matrix1) << endl;
    cout << "Matrix2: " << glm::to_string(matrix2) << endl;
    cout << "Add M1 to M2: " << glm::to_string(matrix2 * matrix1) << endl;

    return 0;
}
