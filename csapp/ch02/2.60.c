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

unsigned
replace_byte(unsigned x, int i, unsigned char b)
{
  int off = i << 3;
  return (x & ~(0xFF << off)) | (b << off); 
}

int 
main(int argc, char *argv[])
{
  test_show_bytes(replace_byte(0x12345678, 2, 0xAB)); /* 0x12AB5678 */
  test_show_bytes(replace_byte(0x12345678, 0, 0xAB)); /* 0X123456AB */

  exit(EXIT_SUCCESS);
}