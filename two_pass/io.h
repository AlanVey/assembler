/*
I/O Header file
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char** readfile(FILE* file, uint32_t numLines);
uint32_t countLines(FILE* file);