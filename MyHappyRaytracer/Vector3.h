#include <math.h>
#include <stdio.h>

typedef struct {
	double Vect3[3] = { 0,0,0 };
} Vector3;

double x(Vector3 vector) {
	return vector.Vect3[0];
}

double y(Vector3 vector) {
	return vector.Vect3[1];
}

double z(Vector3 vector) {
	return vector.Vect3[2];
}


//utilities
Vector3 operator_negative(Vector3 vector) {
	vector.Vect3[0] = vector.Vect3[0] * -1;
	vector.Vect3[1] = vector.Vect3[1] * -1;
	vector.Vect3[2] = vector.Vect3[2] * -1;
	return vector;
}

double operator_element(Vector3 vector, int i) {
	return vector.Vect3[i];
}

Vector3 operator_plusEqual(Vector3 vector, Vector3 vector_toAdd) {
    vector.Vect3[0] += vector_toAdd.Vect3[0];
	vector.Vect3[1] += vector_toAdd.Vect3[1];
	vector.Vect3[2] += vector_toAdd.Vect3[2];
    return vector;
}

Vector3 operator_timesEqual(Vector3 vector ,const double t) {
    vector.Vect3[0] *= t;
	vector.Vect3[1] *= t;
	vector.Vect3[2] *= t;
    return vector;
}

Vector3 operator_dividedEqual(Vector3 vector, const double t) {
	vector.Vect3[0] *= 1/t;
	vector.Vect3[1] *= 1/t;
	vector.Vect3[2] *= 1/t;
	return vector;
}

double length(Vector3 vector){
    return sqrt(length_squared(vector));
}

double length_squared(Vector3 vector){
	double return_this = vector.Vect3[0] * vector.Vect3[0] + vector.Vect3[1] * vector.Vect3[1] + vector.Vect3[2] * vector.Vect3[2];
	return return_this;
}

void print_vector3(Vector3 vector) {
	printf("%g %g %g", vector.Vect3[0], vector.Vect3[1], vector.Vect3[2]);
}

