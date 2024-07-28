#include <stdio.h>
#include <stdlib.h>

int
int_shifts_are_arithmetic()
{
  int n = -1; /* 0x7FFFFFFF */
  
  return n >> 1 == -1 ? 1 : 0; 
}

int
main(int argc, char *argv[])
{
  printf("%s\n", int_shifts_are_arithmetic() ? "산술 시프트" : "논리 시프트");

  exit(EXIT_SUCCESS);
}