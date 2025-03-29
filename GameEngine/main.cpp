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

static vec3 CrossProduct(vec3 a, vec3 b, vec3 source)
{

	vec3 aVec = source-a;
	vec3 bVec = source-b;
	vec3 cross = glm::cross(aVec, bVec);
	cross = glm::normalize(cross);

	//cout << "Cross = " << glm::to_string(cross) << endl;
	return cross;
}

static void findCuboid(vec3 _a, vec3 _b, vec3 _c) {

	int depth = 5;

	//Getting vectors
	vec3 ab = _b - _a; //a to b
	vec3 ac = _c - _a; //a to c
	vec3 cb = _b - _c; //c to b
	
	//Getting point d
	vec3 dvector = ab + ac; 
	vec3 d = dvector + _a; //gives us point d

	
	vec3 cross = CrossProduct(ab, ac, _a); // top left corner
	cout << "Cross Product: " << to_string(cross) << endl;

	cross = cross * depth;
	
	//other corners of the cube (points)
	vec3 a2 = _a + cross;
	vec3 b2 = _b + cross;
	vec3 c2 = _c + cross;
	vec3 d2 = d + cross;

	cout << "3d Cuboid's points (Corners)" << endl;
	cout << "a: " << to_string(_a) << endl;
	cout << "b: " << to_string(_b) << endl;
	cout << "c: " << to_string(_c) << endl;
	cout << "d: " << to_string(d) << endl;

	cout << "a2: " << to_string(a2) << endl;
	cout << "b2: " << to_string(b2) << endl;
	cout << "c2: " << to_string(c2) << endl;
	cout << "d2: " << to_string(d2) << endl;

}

int main(void)
{
	vec3 a = { -3,1,2 };
	vec3 b = { 0,4,1 };
	vec3 c = { 1,-2,5 };

	findCuboid(a, b, c);
	
	return 0;
}
