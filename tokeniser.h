/*
Tokeniser header file
*/

#include "io.h"
#include "string.h"

#define INSTR_MAX_ARGS 5 

char*** tokeniser(char* path);
char** tokeniseLine(char* line);