#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool
is_little_endian()
{
  int x;
  char *ptr;
  
  x = 0x01;
  ptr = (char *)&x;

  return *ptr == 0x01 ? true : false;
}

int 
main(int argc, char *argv[])
{
	printf("%s\n", is_little_endian() ? "작은 끝" : "큰 끝");

  exit(EXIT_SUCCESS);
}