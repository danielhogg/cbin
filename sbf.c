// Here .sbf files are a custom binary format used only for example purposes
// in a workshop given on Feb 1, 2019. The files are 'Sample Binary Format'.


#include <stdio.h>
#include <stdlib.h>
#include <sbf.h>


float float_rand( float min, float max )
{
    float scale = rand() / (float) RAND_MAX;
    return min + scale * ( max - min );
}

void write_sbf(char * file_path, struct SbfHeader * header, int seed){
	FILE * p_file;
	p_file = fopen(file_path, "w+");

	// This is a standin
	int header_size = 12;
	fwrite(header, header_size, 1, p_file);

	srand(seed);

	int x_dim = header->x_dim;
	int y_dim = header->y_dim;
	int min_temp = 18.3;
	int max_temp = 27.5;

	printf("x_dim: %d, y_dim: %d\n", x_dim, y_dim);

	float ** sbf_array = malloc(sizeof(float *) * x_dim);
	int i, j;
	for (i = 0; i < x_dim; i++){
		sbf_array[i] = malloc(sizeof(float) * y_dim);
	}

	for (i = 0; i < x_dim; i++){
		for (j = 0; j < y_dim; j++){
			sbf_array[i][j] = float_rand(min_temp, max_temp);
		}
	}

	for (i = 0; i < x_dim; i++){
		fwrite(sbf_array[i], sizeof(float), y_dim, p_file);
	}

	fclose(p_file);
}

float ** read_sbf(char * file_path, int * x_dim, int * y_dim){

	float ** test;
	return test;
}