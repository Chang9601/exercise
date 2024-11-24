#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool a(int x)
{
  return x;
}

bool b(int x)
{
  return ~x;
}

bool c(int x)
{
  return x & 0xFF;
}

bool d(int x)
{
  return x & (0xFF << 24);
}

int
main(int argc, char *argv[])
{
  printf("0x00000001: %d\n", a(0x00000001));
  printf("0x00000000: %d\n", a(0x00000000));
  printf("0x12345670: %d\n", b(0x12345670));
  printf("0xFFFFFFFF: %d\n", b(0xFFFFFFFF));
  printf("0x00000011: %d\n", c(0x00000001));
  printf("0x12345600: %d\n", c(0x12345600));
  printf("0x11000000: %d\n", d(0x11000000));
  printf("0x00876543: %d\n", d(0x00876543));

  exit(EXIT_SUCCESS);
}