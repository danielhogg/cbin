CC=gcc
CFLAGS=-I.

all: generate_sample process_sample

generate_sample: generate_sample.c
	$(CC) $(CFLAGS) -o generate_sample sbf.c generate_sample.c

process_sample: process_sample.c
	$(CC) $(CFLAGS) -o process_sample sbf.c process_sample.c
