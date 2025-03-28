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
//Vector Multiplication
static vec3 pos = { 2,2,2 };
static void MultiplyVectors() {

	vec3 dest = { 1, 0, 0 };
	vec3 dir = dest - pos;
	dir = normalize(dir);
	pos += (dir * 0.1f);
	cout << glm::to_string(pos) << endl;
}

static void Distance() {

	vec3 p1 = { 2, 1, 0 };
	vec3 p2 = { 2, 1, 2 };
	float distance = glm::distance(p1, p2);
	cout << "Distance = " << distance << endl;
}


static void DotProduct()
{
	vec3 source = { 0, 0, 0 };
	vec3 a = { 0, 2, 0 };
	vec3 b = { 1, 1, 0 };

	vec3 aVec = a - source;
	vec3 bVec = b - source;

	aVec = glm::normalize(aVec);
	bVec = glm::normalize(bVec);

	float dot = glm::dot(aVec, bVec);
	cout << "Dot = " << dot << endl;
}

static void CrossProduct()
{
	vec3 source = { 0, 0, 0 };
	vec3 a = { 0, 2, 0 };
	vec3 b = { 1, 1, 0 };

	vec3 aVec = a - source;
	vec3 bVec = b - source;

	vec3 cross = glm::cross(aVec, bVec);
	cross = glm::normalize(cross);

	cout << "Cross = " << glm::to_string(cross) << endl;
}

static void findCuboid(vec3 _a, vec3 _b, vec3 _c) {

}

int main(void)
{
	CrossProduct();
	return 0;
}
