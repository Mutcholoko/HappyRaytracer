#ifndef VECTOR3_H
#define VECTOR3_H
#include <math.h>
#include <stdio.h>

typedef struct {
	double Vect3[3];
} Vector3;

typedef Vector3 color;
typedef Vector3 point3;

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

Vector3 operator_sumOfTwoVect3(Vector3 vect1, Vector3 vect2) {
	Vector3 return_vec;
	return_vec.Vect3[0] = vect1.Vect3[0] + vect2.Vect3[0];
	return_vec.Vect3[1] = vect1.Vect3[1] + vect2.Vect3[1];
	return_vec.Vect3[2] = vect1.Vect3[2] + vect2.Vect3[2];
	return return_vec;
}

Vector3 operator_difOfTwoVect3(Vector3 vect1, Vector3 vect2) {
	Vector3 return_vec;
	return_vec.Vect3[0] = vect1.Vect3[0] - vect2.Vect3[0];
	return_vec.Vect3[1] = vect1.Vect3[1] - vect2.Vect3[1];
	return_vec.Vect3[2] = vect1.Vect3[2] - vect2.Vect3[2];
	return return_vec;
}

Vector3 operator_multiplOfTwoVect3(Vector3 vect1, Vector3 vect2) {
	Vector3 return_vec;
	return_vec.Vect3[0] = vect1.Vect3[0] * vect2.Vect3[0];
	return_vec.Vect3[1] = vect1.Vect3[1] * vect2.Vect3[1];
	return_vec.Vect3[2] = vect1.Vect3[2] * vect2.Vect3[2];
	return return_vec;
}

Vector3 operator_multiplyVect3ByT(Vector3 vect1, double t) {
	Vector3 return_vec;
	return_vec.Vect3[0] = vect1.Vect3[0] * t;
	return_vec.Vect3[1] = vect1.Vect3[1] * t;
	return_vec.Vect3[2] = vect1.Vect3[2] * t;
	return return_vec;
}

Vector3 operator_divideVect3ByT(Vector3 vect1, double t) {
	Vector3 return_vec;
	return_vec.Vect3[0] = vect1.Vect3[0] * 1/t;
	return_vec.Vect3[1] = vect1.Vect3[1] * 1/t;
	return_vec.Vect3[2] = vect1.Vect3[2] * 1/t;
	return return_vec;
}

double dot(Vector3 vect1, Vector3 vect2) {
	double return_sum = 0;
	return_sum += vect1.Vect3[0] * vect2.Vect3[0];
	return_sum += vect1.Vect3[1] * vect2.Vect3[1];
	return_sum += vect1.Vect3[2] * vect2.Vect3[2];
	return return_sum;
}

Vector3 cross(Vector3 vect1, Vector3 vect2) {
	Vector3 return_vector;
	return_vector.Vect3[0] = (vect1.Vect3[1] * vect2.Vect3[2]) - (vect1.Vect3[2] * vect2.Vect3[1]);
	return_vector.Vect3[1] = (vect1.Vect3[2] * vect2.Vect3[0]) - (vect1.Vect3[0] * vect2.Vect3[2]);
	return_vector.Vect3[2] = (vect1.Vect3[0] * vect2.Vect3[1]) - (vect1.Vect3[1] * vect2.Vect3[0]);
	return return_vector;
}

Vector3 unit_vec(Vector3 vector) {
	Vector3 return_vector;
	return_vector = operator_divideVect3ByT(vector, length(vector)); //it will divide the vector by its length
	return return_vector;
}

#endif