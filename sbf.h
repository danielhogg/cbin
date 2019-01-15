

struct SbfHeader {
	int file_version;
    int x_dim;
    int y_dim;
};

void write_sbf(char * file_path, struct SbfHeader * header, int seed);
float ** read_sbf(char * file_path, int * x_dim, int * y_dim);