#include "multiply.h"

uint32_t multiply_instr(char** line)
{
  uint32_t instr;
  if(strcmp(line[0], "mul") == 0)
  {
    instr = 0xE0000090;
    instr |= (REG_D(regToInt(line[1])) | REG_M(regToInt(line[2])) | REG_S(regToInt(line[3])));
  }
  else
  {
    instr = 0xE0200090;
    instr |= (REG_D(regToInt(line[1])) | REG_M(regToInt(line[2])) 
            | REG_S(regToInt(line[3])) | REG_N(regToInt(line[4])));
  }
  return instr;
}

