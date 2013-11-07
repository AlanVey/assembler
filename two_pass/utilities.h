#include <stdint.h>
#include <stdlib.h>

#define REG_D(x) (x << 16)
#define REG_N(x) (x << 12)
#define REG_S(x) (x << 8)
#define REG_M(x) (x << 0)

uint32_t regToInt(char* reg);
uint32_t toInt (char* int);
uint8_t arrayContains(char* item, char** array, uint32_t arrayLen);
