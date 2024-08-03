long A[R][S][T];

long store_ele(long i, long j, long k, long *dest)
{
  *dest = A[i][j][k];

  return sizeof(A);
}

/*
 * %rdi: i, %rsi: j, %rdx: k, %rcx: dest
 * store_ele:
 *   leaq    (%rsi, %rsi, 2), %rax
 *   leaq    (%rsi, %rax, 4), %rax
 *   movq    %rdi, %rsi
 *   salq    $6, %rsi
 *   addq    %rsi, %rdi
 *   addq    %rax, %rdi
 *   addq    %rdi, %rdx
 *   movq    A(,%rdx,8), %rax
 *   movq    %rax, (%rcx)
 *   movl    $3640, %eax
 *   ret
 */

/* 
 * T A[R][C] -> &A[i][j] = xA + L(C * i + j)
 *
 * A. T A[D][R][C] -> &A[i][j][k] = xA + L(R * C * i) + L(C * j + k)
 * B. long A[7][5][13]
 */