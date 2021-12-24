#include <stdio.h>
#include <stdlib.h>

int main(void) {

	//image parameters
	int img_width = 256;
	int img_height = 256;

	//rendering
	printf("P3\n");
	printf("%d %d", img_width, img_height);
	printf("\n255\n");

	for (int j = img_height-1; j >= 0 ; j--) {
		//progress handling, not working yet so commented out
		//printf("#lines remaining: %d", j);
		for (int i = 0; i < img_width; i++) {
			double red = ((double) i) / (img_width - 1);
			double green = ((double)j) / (img_height - 1);
			double blue = 0.25;

			int img_r = (int)(255.999 * red);
			int img_g = (int)(255.999 * green);
			int img_b = (int)(255.999 * blue);
		
			printf("%d %d %d\n", img_r, img_g, img_b);
		}
	}
	//faulty progress handling
	//printf("#Done.\n");

	return 0;
}