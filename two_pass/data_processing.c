

uint32_t data_processing(char** instr)
{
  uint32_t bin_instr = 0xE0000000;
  char* compute_results[6] = {"and", "eor", "sub", "rsb", "add", "orr"};
  char* assignment = "mov";
  char* set_CPRS [3] = {"tst", "teq", "cmp"};

  if(strcmp(instr[0], assignment) == 0)
    bin_instr |= (0xE0900000 | process_op2(instr[2]) | REG_D(regToInt(instr[1])));
  else if(arrayContains(instr[0], set_CPRS, 3))
  {
    bin_instr |= (0xE0000000 | process_op2(instr[2]) | REG_N(regToInt(instr[1])));

    if (strcmp(instr[0], "tst"))
      instr |= 0x0110000;
    else if(strcmp(instr[0], "teq"))
      instr |= 0x01300000;
    else
      instr |= 0x01500000;
  }
  else
  {
    bin_instr |= (process_op2(instr[3]) | REG_N(regToInt(instr[2])) | REG_D(regToInt(instr[1])));

    if (strcmp(instr[0], "and"))
      return instr;
    else if(strcmp(instr[0], "eor"))
      instr |= 0x00200000;
    else if(strcmp(instr[0], "sub"))
      instr |= 0x00400000;
    else if(strcmp(instr[0], "rsb"))
      instr |= 0x00600000;
    else if(strcmp(instr[0], "add"))
      instr |= 0x00800000;
    else
      instr |= 0x01800000;
  }
  return bin_instr;
}
uint32_t process_op2(char* op2)
{
  if(op2[0] == '#')
    return process_expression(&op2[1]);
}

uint32_t process_expression(char* expression)
{

}