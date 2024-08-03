#define NR(n) (3 * (n))
#define NC(n) (4 * (n) + 1)

long sum_col(long n, long A[NR(n)][NR(n)], long j)
{
  long i;
  long result = 0;
  for (i = 0; i < NR(n); i++)
    result += A[i][j];
  return result;
}

/* 
 * %rdi: n, %rsi: A, %rdx: j
 * sum_col:
 *   leaq    1(,%rdi,4), %r8
 *   leaq    (%rdi,%rdi,2), %rax
 *   movq    %rax, %rdi
 *   testq   %rax, %rax
 *   jle     .L4
 *   salq    $3, %r8
 *   leaq    (%rsi,%rdx,8), %rcx
 *   movl    $0, %eax
 *   movl    $0, %edx
 * .L3:
 *   addq    (%rcx), %rax
 *   addq    $1, %rdx
 *   addq    %r8, %rcx
 *   addq    %rdi, %rdx
 *   jne     .L3
 *   rep; ret
 * .L4:
 *   movl    $0, %eax
 *   ret
 */

