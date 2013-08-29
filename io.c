/*
file opener + binary writer
*/

#define MAX_LINE_SIZE 512

#include "io.h"

char** readfile(FILE* file, uint32_t numLines)
{
  uint32_t line = 0;
  char** lines = calloc(numLines, MAX_LINE_SIZE);

  fseek(file, 0, SEEK_SET);
  for (; fgets(lines[line], MAX_LINE_SIZE, file) != NULL; line++);

  return lines;
}


/*=============================Helper Methods=======================*/

uint32_t countLines(FILE* file)
{
  uint32_t lines = 1;
  uint64_t chars = 0;
  int ch = 0;

  fseek(file, 0, SEEK_SET);
  while ((ch = fgetc(file)) != EOF)
  {
    if((char)ch == '\n')
      lines++;
    chars++;
    fseek(file, chars, SEEK_SET);
  }
  return lines;
}