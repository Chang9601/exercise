#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char* byte_ptr;

void
show_bytes(byte_ptr start, size_t len)
{
  size_t i;

  for (i = 0; i < len; i++)
    printf("0x%.2x\t", start[i]);

  printf("\n");
}

void
show_int(int x)
{
  show_bytes((byte_ptr)&x, sizeof(x));
}

void 
test_show_bytes(int val) 
{
  show_int(val);
}


int
fn(int x, int y)
{
  return (x & 0xFF) | (y & ~0xFF);
}

int 
main(int argc, char *argv[])
{
  test_show_bytes(fn(0x89ABCDEF, 0x76543210)); /* Ox765432EF */

  exit(EXIT_SUCCESS);
}