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

void write_sbf(char * file_path, int x_dim, int y_dim, int seed){
    FILE * p_file;
    p_file = fopen(file_path, "wb");

    int file_version = 1;

    fwrite(&file_version, sizeof(int), 1, p_file);
    fwrite(&x_dim, sizeof(int), 1, p_file);
    fwrite(&y_dim, sizeof(int), 1, p_file);

    srand(seed);

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

    for (i = 0; i < x_dim; i++){
        free(sbf_array[i]);
    }
    free(sbf_array);

    fclose(p_file);
}

float read_sbf(char * file_path){
    FILE * p_file;
    p_file = fopen(file_path, "rb");

    int x_dim;
    int y_dim;
    int file_version;

    fread(&file_version, sizeof(int), 1, p_file);
    fread(&x_dim, sizeof(int), 1, p_file);
    fread(&y_dim, sizeof(int), 1, p_file);

    printf("File version: %d\n", file_version);
    printf("File header read - x_dim: %d, y_dim: %d\n", x_dim, y_dim);

    int i, j;

    float * row_mean = malloc(sizeof(float) * x_dim);
    float ** sbf_array = malloc(sizeof(float *) * x_dim);

    for (i = 0; i < x_dim; i++){
        sbf_array[i] = malloc(sizeof(float) * y_dim);
    }

    for (i = 0; i < x_dim; i++){
        fread(sbf_array[i], sizeof(float), y_dim, p_file);
    }

    for (i = 0; i < x_dim; i++){
        float tmp_total = 0;
        for (j = 0; j < y_dim; j++){
            tmp_total += sbf_array[i][j];
        }
        row_mean[i] = tmp_total / (float)y_dim;
    }

    for (i = 0; i < x_dim; i++){
        free(sbf_array[i]);
    }
    free(sbf_array);

    float total = 0;
    for (i = 0; i < x_dim; i++){
        total += row_mean[i];
    }

    free(row_mean);

    fclose(p_file);

    float sbf_mean = total / (float)x_dim;
    return sbf_mean;
}