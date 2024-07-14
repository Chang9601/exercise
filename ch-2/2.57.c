#include <stdio.h>
#include <stdlib.h>

typedef unsigned char* byte_pointer;

void
show_bytes(byte_pointer start, size_t len)
{
  size_t i;

  for (i = 0; i < len; i++)
    printf("0x%.2x\t", start[i]);

  printf("\n");
}

void 
show_short(short x)
{
  show_bytes((byte_pointer)&x, sizeof(x));
}

void
show_long(long x)
{
  show_bytes((byte_pointer)&x, sizeof(x));
}

void
show_double(double x)
{
  show_bytes((byte_pointer)&x, sizeof(x));
}

void 
test_show_bytes(int val)
{
    short sval = (short) val;
    long lval = (long) val;
    double dval = (double) val;

    show_short(sval);
    show_long(lval);
    show_double(dval);
}

int 
main(int argc, char *argv[])
{
	test_show_bytes(12345);

  exit(EXIT_SUCCESS);
}