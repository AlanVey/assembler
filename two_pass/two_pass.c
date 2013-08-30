/*
Two Pass assembly
*/

#include "two_pass.h"

node* createSymbolTable(char*** tokens, uint32_t lines)
{
  node* symbolTable = makeRBT();
  char* token;
  uint32_t i;
  for(i = 0; i < lines; i++)
  {
    token = tokens[i][0];
    if(token[strlen(token) - 1] == ':')
      insert(symbolTable, NULL, token, &token);
      tokens[i][0] = tokens[i][1];
  }
  return symbolTable;
}

uint32_t* assemble(char*** tokens, uint32_t lines)
{
  uint32_t i;
  uint32_t* assembledInstrs = calloc(lines, 8);
  char* dataprocessing[12] = {"add", "sub", "rsb", "and", "eor", "orr", "mov", "tst", "teq", "cmp", "lsl", "andeq"};
  char* multiply[2] = {"mul", "mla"};
  char* singleDataTransfer[2] = {"ldr", "str"};
  char* branch[7] = {"beq", "bne", "bge", "blt", "bgt", "ble", "b"};
  node* symbolTable = createSymbolTable(tokens, lines);

  for (i = 0; i < lines; i++)
  {
    if(arrayContains(tokens[i][0], dataprocessing, 12))
      assembledInstrs[i] = data_processing(tokens[i]);
    else if(arrayContains(tokens[i][0], multiply, 2))
      assembledInstrs[i] = multiply_instr(tokens[i]);
    else if(arrayContains(tokens[i][0], singleDataTransfer, 2))
      assembledInstrs[i] = single_data_transfer(tokens[i], symbolTable);
    else if(arrayContains(tokens[i][0], branch, 7))
      assembledInstrs[i] = branch_instr(tokens[i], symbolTable);
    else
      printf("Unknown command");
  }
  return assembledInstrs;
}




