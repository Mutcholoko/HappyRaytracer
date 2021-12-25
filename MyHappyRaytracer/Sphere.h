#ifndef SPHERE_H
#define SPHERE_H

#include "Hittable.h"
#include "Vector3.h"

typedef struct {
	point3 center;
	double radius;
}Sphere;

bool hit_sphere(Sphere sphere, Ray r, double t_min, double t_max, hit_record rec) {
	Vector3 oc = operator_difOfTwoVect3(r.origin, sphere.center);
	double a = length_squared(r.direction);
	double half_b = dot(oc, r.direction);
	double c = length_squared(oc) - (sphere.radius * sphere.radius);
	double discriminant = half_b * half_b - (a * c);

	if (discriminant < 0) return false;

	double sqrtd = sqrt(discriminant); //square-rooted
	double root = (-half_b - sqrtd) / a;

	if (root<t_min || root>t_max) {
		root = (-half_b + sqrtd) / a;
		if (root<t_min || root>t_max) {
			return false;
		}
	}
	rec.t = root;
	rec.p = at(r, rec.t);
	Vector3 outward_normal = operator_divideVect3ByT(operator_difOfTwoVect3(rec.p, sphere.center), sphere.radius);
	rec.set_face_normal(r, outward_normal);

	return true;
}

#endif // !SPHERE_H
