#ifndef RAY_H
#define RAY_H

#include "Vector3.h"

typedef struct {
	point3 origin;
	Vector3 direction;
}Ray;

//returns the origin of a specified ray
point3 origin(Ray ray) {
	return ray.origin;
}

//returns the direction of a specified ray
Vector3 direction(Ray ray) {
	return ray.direction;
}

point3 at(Ray ray, double t) {
	Ray return_ray = ray;
	return_ray.origin = operator_plusEqual(return_ray.origin, operator_multiplyVect3ByT(return_ray.direction, t));
	return return_ray.origin;
}

Ray fill_RayDirection(Ray ray, Vector3 v_Filler) {
	Ray ray_return = ray;
	ray_return.direction.Vect3[0] = x(v_Filler);
	ray_return.direction.Vect3[1] = y(v_Filler);
	ray_return.direction.Vect3[2] = z(v_Filler);
	return ray_return;
}

Ray fill_RayOriginwithOrigin(Ray ray, point3 rayOrig_toAdd) {
	Ray ray_return = ray;
	ray_return.origin.Vect3[0] = rayOrig_toAdd.Vect3[0];
	ray_return.origin.Vect3[1] = rayOrig_toAdd.Vect3[1];
	ray_return.origin.Vect3[2] = rayOrig_toAdd.Vect3[2];
	return ray_return;
}

Ray initialize_ray() {
	Ray ray_return;
	ray_return.origin.Vect3[0] = 0;
	ray_return.origin.Vect3[1] = 0;
	ray_return.origin.Vect3[2] = 0;
	ray_return.direction.Vect3[0] = 0;
	ray_return.direction.Vect3[1] = 0;
	ray_return.direction.Vect3[2] = 0;
	return ray_return;
}

#endif // !RAY_H
