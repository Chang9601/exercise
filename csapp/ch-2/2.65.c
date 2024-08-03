#include <stdio.h>
#include <stdlib.h>

int odd_ones(unsigned x)
{
  x ^= x >> 16;
  x ^= x >> 8;
  x ^= x >> 4;
  x ^= x >> 2;
  x ^= x >> 1;

  return x & 0x01;
}

int
main(int argc, char *argv[])
{
  printf("0x00000000: %d\n", odd_ones(0x00000000));
  printf("0x11111111: %d\n", odd_ones(0x11111111));
  printf("0x10110000: %d\n", odd_ones(0x10110000));
  printf("0x01010111: %d\n", odd_ones(0x01010111));
  
  exit(EXIT_SUCCESS);
}