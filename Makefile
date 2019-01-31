MINGW=x86_64-w64-mingw32-gcc
CC=gcc
CFLAGS=-I.

all: generate_sample process_sample process_sample.exe

clean:
	rm generate_sample process_sample process_sample.exe

generate_sample: generate_sample.c
	$(CC) $(CFLAGS) -o generate_sample sbf.c generate_sample.c

process_sample: process_sample.c
	$(CC) $(CFLAGS) -o process_sample sbf.c process_sample.c

process_sample.exe: process_sample.c
	$(MINGW) $(CFLAGS) -o process_sample.exe sbf.c process_sample.c
