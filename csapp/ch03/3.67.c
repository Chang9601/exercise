typedef struct {
  long a[2];
  long *p;
} strA;

typedef struct {
  long u[2];
  long q;
} strB;

/*
 * process:
 *   movq   %rdi, %rax
 *   movq   24(%rsp), %rdx
 *   movq   (%rdx), %rdx
 *   movq   16(%rsp), %rcx
 *   movq   %rcx, (%rdi)
 *   movq   8(%rsp), %rcx
 *   movq   %rcx, 8(%rdi)
 *   movq   %rdx, 16(%rdi)
 *   ret
 */
strB process(strA s) {
  strB r;
  r.u[0] = s.a[1];
  r.u[1] = s.a[0];
  r.q = *s.p;
  return r;
}

/*
 * %rdi: x, %rsi: y, %rdx: z
 * eval:
 *   subq   $104, %rsp
 *   movq   %rdx, 24(%rsp)
 *   leaq   24(%rsp), %rax
 *   movq   %rdi, (%rsp)
 *   movq   %rsi, 8(%rsp)
 *   movq   %rax, 16(%rsp)
 *   leaq   64(%rsp), %rdi
 *   call   process
 *   movq   72(%rsp), %rax
 *   addq   64(%rsp), %rax
 *   addq   80(%rsp), %rax
 *   addq   $104, %rsp
 *   ret
 */
long eval(long x, long y, long z) {
  strA s;
  s.a[0] = x;
  s.a[1] = y;
  s.p = &z;
  strB r = process(s);
  return r.u[0] + r.u[1] + r.q;
}

/*
 * A. x(0) y(8) &z(16) z(24)
 * B. %rsp + 64(%rdi)
 * C. %rsp
 * D. %rdi
 * E. x(0) y(8) &z(16) z(24) y(64) x(72) z(80)
 * F. 호출 함수는 스택 공간을 할당하고 해당 공간의 주소를 호출된 함수에 전달한다. 호출된 함수는 이 공간에 데이터를 저장하고 그 주소를 반환 주소로 사용한다.
 */