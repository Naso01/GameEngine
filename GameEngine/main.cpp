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
		cout << "dir: " << to_string(dir) << endl;
		_position += (dir * _speed);
		cout <<"Position: " << glm::to_string(_position) << endl;
		
		//if the distance between _position and _destination is <= distance of the next step, then we will overshoot our destination
		if ((glm::distance(_position, _destination)) <= 
			(glm::distance(_position + (dir * _speed), _destination )) ) {

			_position = _destination; 

		}

		steps++;

	}
	return steps;
}


int main(void)
{
	//stepCount(vec3 _destination, vec3 _position, float _speed)
	int steps = stepCount({ 1,0,0 }, { 2, 2, 2 }, 0.1f);

	cout<< "Steps:" << steps << endl;


	return 0;
}
