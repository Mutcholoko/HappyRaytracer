#include <stdio.h>
#include <stdlib.h>
#include "Color.h"
#include "Vector3.h"

int main(void) {

	//image parameters
	double img_width = 256.0;
	double img_height = 256.0;

	//rendering
	printf("P3\n");
	printf("%d %d", (int)img_width, (int)img_height);
	printf("\n255\n");

	for (int j = img_height-1; j >= 0 ; j--) {
		//progress handling
		fprintf(stderr, "lines remaining: %d\n", j);

		for (int i = 0; i < img_width; i++) {
			color p_color = { (double)i / (img_width - 1), (double)j / (img_height - 1), 0.25 };
			write_color(p_color);
		}
	}
	fprintf(stderr, "Done.\n");

	return 0;
}