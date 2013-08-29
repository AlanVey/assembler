/*
Tokeniser
*/

#include "tokeniser.h"

char*** tokeniser(char* path)
{
  char*** output;
  FILE* file = fopen(path, "rt");
  char** lines = readfile(file, countLines(file));
  uint32_t line = 0;

  while (line == 0)// total number less than total lines
  {
    output[line] = tokeniseLine(lines[line]);
  }
  fclose(file);
  return output;
}

char** tokeniseLine(char* line)
{
  char** tokens = calloc(1, INSTR_MAX_ARGS * sizeof(void*));
  uint32_t token = 0;
  tokens[token] = strtok(line, " ");

  while (token < INSTR_MAX_ARGS)
  {
    tokens[++token] = strtok(NULL, " ");
  }
  return tokens;
}