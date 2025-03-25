#include "GameController.h"

using namespace glm;

//Vector Addition
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

//Vector Subtraction
static void SubtractionVectors() {

	vec2 a = { 3, 5 };
	vec2 b = { 2, -1 };
	vec2 c = b - a; // a to b
	vec2 d = a - b; // b to a
	cout << glm::to_string(c) << "	Magnitude: " << glm::length(c)<< endl;

	cout << glm::to_string(d) << "	Magnitude: " << glm::length(d) << endl;

}
static vec3 pos = { 2,2,2 };
static void MultiplyVectors() {

	vec3 dest = { 1, 0, 0 };
	vec3 dir = dest - pos;
	dir = normalize(dir);
	pos += (dir * 0.1f);
	cout << glm::to_string(pos) << endl;
}


int main(void)
{
	for (int count = 0; count < 10; count++)
		MultiplyVectors();

	return 0;
}
