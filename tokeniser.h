/*
Tokeniser header file
*/

#include "io.h"
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

#define INSTR_MAX_ARGS 5 

char*** tokeniser(char* path);
char** tokeniseLine(char* line);