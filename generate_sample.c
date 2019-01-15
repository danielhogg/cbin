#include <stdio.h>
#include <stdlib.h>
#include <sbf.h>


int main(){
    int fixed_seed = 74475;
    char * file_path = "./sample_data.sbf";

    int width = 2000;
    int height = 2400;

    write_sbf(file_path, width, height, fixed_seed);

    return 0;
}

// gcc -I . -o output dsbf.c generate_sample.c
// should build some kind of makefile