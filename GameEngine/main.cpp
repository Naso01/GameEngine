#include "GameController.h"

using namespace glm;


int main() {
	mat4 matrix = mat4(1.0f);
	vec3 scaleVec = { 2, 2, 2 };
	matrix = scale(matrix, scaleVec);
	cout << "Scale Matrix: " << to_string(matrix) << endl;

	return 0;
}
