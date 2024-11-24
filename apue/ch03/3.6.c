/*
 * 파일의 어느 위치에서나 lseek() 함수 및 read() 함수를 호출할 수 있다.
 * write() 함수는 데이터를 쓰기 전에 파일 오프셋을 자동으로 파일 끝으로 재설정하므로 파일 끝 이외의 위치에 데이터를 쓸 수 없다.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SZ 4096

static void do_lseek(int, int);
static void do_read(int, char []);

int
main(int argc, char *argv[])
{
  int fd;
  size_t len;
  off_t off;
  char buf[BUF_SZ], str[] = "sample";

  if (argc != 2) {
    fprintf(stderr, "usage: %s file ...\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if ((fd = open(argv[1], O_RDWR | O_APPEND)) == -1) {
    perror("open()");
    exit(EXIT_FAILURE);
  }

  if (lseek(fd, 0, SEEK_CUR) == -1) {
    perror("lseek()");
    close(fd);
    exit(EXIT_FAILURE);
  }

  do_lseek(fd, 8);
  do_read(fd, buf);

  len = strlen(str);

  if (write(fd, str, len) != len) {
    perror("write()");
    close(fd);
    exit(EXIT_FAILURE);
  }

  do_lseek(fd, 0);
  do_read(fd, buf);

  if (close(fd) == -1) {
    perror("close()");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}

static void
do_lseek(int fd, int off)
{
  if (lseek(fd, off, SEEK_SET) == -1) {
    perror("lseek()");
    close(fd);
    exit(EXIT_FAILURE);
  }
}

static void
do_read(int fd, char buf[])
{
  ssize_t n;

  while((n = read(fd, buf, BUF_SZ - 1)) > 0) {
    buf[n] = '\0';
    printf("%s\n", buf);
  }

  if (n == -1) {
    perror("read()");
    close(fd);
    exit(EXIT_FAILURE);
  }
}