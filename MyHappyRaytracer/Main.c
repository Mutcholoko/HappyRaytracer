#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Color.h"
#include "Ray.h"
#include "Vector3.h"

//returns if the ray hits sphere
bool hit_Sphere(point3 Center, double radius, Ray r) {
	Vector3 oc = operator_difOfTwoVect3(r.origin, Center);
	double a = dot(r.direction, r.direction);
	double b = 2.0 * dot(oc, r.direction);
	double c = dot(oc, oc) - (radius * radius);
	double discriminant = (b * b) - (4 * a * c);
	
	return(discriminant > 0);
}

//return color red for ray that hits sphere
color ray_Color(Ray r) {
	point3 sphere_c = fill_Vector(0, 0, -1);
	if (hit_Sphere(sphere_c, 0.5, r)) {
		color color_return = fill_Vector(1, 0, 0); //color red
		return color_return;
	}
	Vector3 unit_dir = unit_vec(r.direction);
	double t = 0.5 * (y(unit_dir) + 1.0);
	color aux_color1, aux_color2;
	aux_color1 = fill_Vector(1.0, 1.0, 1.0);
	aux_color2 = fill_Vector(0.5, 0.7, 1.0);
	color color_return = operator_sumOfTwoVect3(operator_multiplyVect3ByT(aux_color1, (1.0 - t)), operator_multiplyVect3ByT(aux_color2, t));
	return color_return; //if is not the ball, then return the bg color
}

int main(void) {

	//image parameters
	const double aspectRatio = 16.0 / 9.0;
	const int img_width = 400;
	const int img_height = (int)(img_width/aspectRatio);

	//camera settings
	double viewport_height = 2.0;
	double viewport_width = aspectRatio * viewport_height;
	double focal_length = 1.0;

	point3 origin = fill_Vector(0.0, 0.0, 0.0);
	Vector3 horizontal = fill_Vector(viewport_width, 0.0, 0.0);
	Vector3 vertical = fill_Vector(0, viewport_height, 0);
	//this is kinda confusing but it actually is just
	//origin - horizontal/2 - vertical/2 - (0,0,focal_length)
	Vector3 lower_left_corner = operator_difOfTwoVect3(operator_difOfTwoVect3      
	(operator_difOfTwoVect3(origin, (operator_divideVect3ByT(horizontal, 2.0))),
		operator_divideVect3ByT(vertical, 2.0)), fill_Vector(0.0, 0.0, focal_length));

	//rendering
	printf("P3\n");
	printf("%d %d", img_width, img_height);
	printf("\n255\n");

	for (int j = img_height-1; j >= 0 ; j--) {
		fprintf(stderr, "lines remaining: %d\n", j);
		for (int i = 0; i < img_width; i++) {
			double u = (double)i / (img_width - 1);
			double v = (double)j / (img_height - 1);

			Ray ray = initialize_ray();
			ray = fill_RayOriginwithOrigin(ray, origin);
			
			//also kinda confusing, but its just:
			//lower_left_corner + u*horizontal + v*vertical - origin
			Vector3 rayDir = operator_difOfTwoVect3(operator_sumOfTwoVect3(operator_sumOfTwoVect3(lower_left_corner, operator_multiplyVect3ByT(horizontal, u)), operator_multiplyVect3ByT(vertical, v)), origin);
			ray = fill_RayDirection(ray, rayDir);

			color p_color = ray_Color(ray);
			write_color(p_color);
		}
	}
	fprintf(stderr, "Done.\n");

	return 0;
}