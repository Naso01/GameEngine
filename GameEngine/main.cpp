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

//Task 1 
static int stepCount(vec3 _destination, vec3 _position, float _speed) {

	int steps = 0;

	while (_position != _destination){

		vec3 dir = _destination - _position; //postion -> destination	
		dir = normalize(dir);
		_position += (dir * _speed);
		cout <<"Position: " << glm::to_string(_position) << endl;
		cout << "Destination: " << glm::to_string(_destination) << endl;
		
		//if the distance between _position and _destination is <= distance of the next step, then we will overshoot our destination
		if ((glm::distance(_position, _destination)) <= 
			(glm::distance(_position + (dir * _speed), _destination )) ) {

			_position = _destination; 

		}

		steps++;

	}
	return steps;
}

//Task 2
static float trianglePerimeter(vec3 _a, vec3 _b, vec3 _c) {

	float perimeter = distance(_a, _b) + distance(_a, _c) + distance(_b, _c);

	return perimeter;
}

static float triangleArea(vec3 _a, vec3 _b, vec3 _c) {

	vec3 aVec = _b - _a;
	vec3 bVec = _c - _a;
	vec3 cross = glm::cross(aVec, bVec);
	//cross = glm::normalize(cross);

	float area = glm::length(cross) / 2;

	return area;
}



int main(void)
{

	vec3 a = { -3,1,2 };
	vec3 b = { 0,4,1 };
	vec3 c = { 1,-2,5 };

	cout << "Triangle Perimeter: " << trianglePerimeter(a, b, c)<<endl;
	cout << "Triangle Area: " << triangleArea(a, b, c) << endl;

	return 0;
}
