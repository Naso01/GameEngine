#include "GameController.h"

using namespace glm;

static void AddVectors() {

	vec2 a = { 3, 5 };
	vec2 b = { 2, -1 };
	vec2 c = a + b;
	cout << glm::to_string(c) << endl;

	vec3 d = { 3, 5, 1};
	vec3 e = { 2, -1, -1 };
	vec3 f = d + e;
	cout << glm::to_string(f) << endl;

}


int main(void)
{
	AddVectors();

	return 0;
}
