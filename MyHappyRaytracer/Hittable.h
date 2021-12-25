#ifndef HITTABLE_H
#define HITTABLE_H

#include "Ray.h"
#include <stdbool.h>

typedef struct {
	point3 p;
	Vector3 normal;
	double t;
	bool front_face;

	void set_face_normal(Ray r, Vector3 outward_normal) {
		front_face = dot(r.direction, outward_normal) < 0;
		normal = front_face ? outward_normal : operator_negative(outward_normal);
	}
}hit_record;

bool hit(Ray r, double t_min, double t_max, hit_record rec);

#endif