#include <stdio.h>
#include <stdlib.h>
#include <sbf.h>

int main(int argc, char *argv[]){
    // Some kind of timing code for this
    printf("Error in process_sample: Process expects exactly 1 command-line argument.");
    printf("Given: 0");
    printf("Error in process_sample: Did not find file at the following path:\n");

    char * file_path = "./sample_data.sbf";
    float mean = read_sbf(file_path);

    printf("Mean of temperature field: %f\n", mean);
}