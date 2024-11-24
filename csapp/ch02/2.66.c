#include <stdio.h>
#include <stdlib.h>

int leftmost_one(unsigned x)
{
  x |= x >> 16;
  x |= x >> 8;
  x |= x >> 4;
  x |= x >> 2;
  x |= x >> 1;

  return x - (x >> 1);
}

int
main(int argc, char *argv[])
{
  printf("0xFFFFFFFF: %d\n", leftmost_one(0xFFFFFFFF) == 0x80000000);
  printf("0x00000000: %d\n", leftmost_one(0x00000000) == 0x00000000);
  printf("0x00345678: %d\n", leftmost_one(0x00345678) == 0x00200000);
  printf("0x0B21F422: %d\n", leftmost_one(0x0B21F422) == 0x08000000);

  exit(EXIT_SUCCESS);
}