#include <stdio.h>
#include <stdlib.h>

int any_odd_one(unsigned x)
{
  return (x & 0x55555555) != 0;
}

int
main(int argc, char *argv[])
{
  printf("0xFFFFFFFF: %d\n", any_odd_one(0xFFFFFFFF));
  printf("0x00010001: %d\n", any_odd_one(0xFFFFFFFF));
  printf("0xAAAAAAAA: %d\n", any_odd_one(0xAAAAAAAA));
  printf("0x00000000: %d\n", any_odd_one(0x00000000));

  exit(EXIT_SUCCESS);
}