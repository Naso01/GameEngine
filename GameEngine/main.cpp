#include "GameController.h"

using namespace glm;



int main() {
	mat4 matrix1 = mat4(1.0f);
	vec3 pos1 = { 0, 0, 0 };
	matrix1 = translate(matrix1, pos1);
	cout << "Translation Matrix 1: " << to_string(matrix1) << endl;

	mat4 matrix2 = mat4(1.0f);
	vec3 pos2 = { 1, 2, 3 };
	matrix2 = translate(matrix2, pos2);
	cout << "Translation Matrix 2: " << to_string(matrix2) << endl;

	return 0;
}
