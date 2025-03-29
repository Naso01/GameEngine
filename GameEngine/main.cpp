#include "GameController.h"

using namespace glm;


int main() {
	mat4 matrix = mat4(1.0f);
	float angle = 0.1f;
	vec3 axis = { 0, 1, 0 };
	matrix = rotate(matrix, angle, axis);
	cout << "Rotation Matrix: " << to_string(matrix) << endl;

	return 0;
}

