#ifndef COLOR_H
#define COLOR_H
#include <stdio.h>
#include "Vector3.h"

void write_color(color p_color) {
	int red = (int)(255.999 * x(p_color));
	int green = (int)(255.999 * y(p_color));
	int blue = (int)(255.99 * z(p_color));
	printf("%d %d %d\n", red, green, blue);
}
#endif