#include "apue.h"

/*
 * 명령줄 인자 중 하나가 symbolic link이면 lstat() 함수는 symbolic link에 대한 정보를 반환한다. 
 * 이와 달리, stat() 함수는 symbolic link가 참조하는 파일을 반환한다. 따라서, symbolic link가 가리키는 파일이 존재하지 않으면 오류가 발생한다.
 * foo-sym -> foo
 * stat()함수: regular
 * lstat() 함수: symbolic link
 */

int
main(int argc, char *argv[])
{
  int         i;
  struct stat buf;
  char        *ptr;

  for (i = 1; i < argc; i++) {
    printf(" %s: ", argv[i]);
    if (lstat(argv[i], &buf) < 0) {
        //err_ret("lstat error");
        perror("lstat()");
        continue;
    }

    if (S_ISREG(buf.st_mode))
        ptr = "regular";
    else if (S_ISDIR(buf.st_mode))
        ptr = "directory";
    else if (S_ISCHR(buf.st_mode))
        ptr = "character special";
    else if (S_ISBLK(buf.st_mode))
        ptr = "block special";
    else if (S_ISFIFO(buf.st_mode))
        ptr = "fifo";
    else if (S_ISLNK(buf.st_mode))
        ptr = "symbolic link";
    else if (S_ISSOCK(buf.st_mode))
        ptr = "socket";
    else
        ptr = "** unknown mode **";
    printf("%s\n", ptr);
  }
  exit(0);
}