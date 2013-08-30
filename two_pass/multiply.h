#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define REG_D(x) (x << 16)
#define REG_N(x) (x << 12)
#define REG_S(x) (x << 8)
#define REG_M(x) (x << 0)

uint32_t multiply_instr(char** line);
uint32_t regToInt(char* reg);