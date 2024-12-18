#include "apue.h"
#include <fcntl.h>

#define RWRWRW (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH |S_IWOTH)

int
main(void)
{
  umask(0);
  if (creat("foo", RWRWRW) == -1)
      err_sys("creat error for foo");
  umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
  if (creat("bar", RWRWRW) == -1) 
      err_sys("create error for bar");
  exit(0);
}