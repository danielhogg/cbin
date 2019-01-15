#include <stdio.h>
#include <stdlib.h>
#include <sbf.h>

int main(int argc, char *argv[]){
    // Some kind of timing code for this

    if (argc != 2){
        printf("ERROR: Process expects exactly 1 command-line argument: (file_path)\n");
        return -1;
    }

    char * file_path = argv[1];
    float mean = read_sbf(file_path);
    printf("Mean of temperature field: %f\n", mean);
}