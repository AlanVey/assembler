#include "RBT_ADT.h"
#include "string.h"
#include "data_processing.h"
#include "multiply.h"
#include "single_data_transfer.h"
#include "branch.h"
#include "stdio.h"
#include "utilities.h"

node* createSymbolTable(char*** tokens, uint32_t lines);
uint32_t* assemble(char*** tokens, uint32_t lines);