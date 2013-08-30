#include "utilities.h"

uint32_t regToInt(char* reg)
{
  char** endPtr;
  return (uint32_t)strtol(&reg[1], endPtr, 10);
}

uint8_t arrayContains(char* item, char** array, uint32_t arrayLen)
{
  uint32_t i;
  for(i = 0; i < arrayLen ; i++)
  {
    if(strcmp(item, array[i]) == 0)
      return 1;
  }
  return 0;
}