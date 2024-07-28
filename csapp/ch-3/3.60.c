/* 
 * %rdi: x, %esi: n
 * loop:
 *   movl   %esi, %ecx
 *   movl   $1, %edx
 *   movl   $0, %eax
 *   jmp    .L2
 * 
 * .L3:
 *   movq   %rdi, %r8
 *   andq   %rdx, %r8
 *   orq    %r8, %rax
 *   salq   %cl, %rdx 
 * 
 * .L2:
 *   testq  %rdx, %rdx # 1 & 1
 *   jne    .L3        # 1 & 1 != 0
 *   rep; ret
 */
long loop(long x, int n)
{
  long result = 0;
  long mask;
  for (mask = 1; mask != 0; mask = mask << n) {
    result |= (x & mask);
  }

  return result;
}
/*
 * A. x: %rdi, n: %esi, result: %rax, mask: %rdx 
 * B. result = 0, mask = 1
 * C. mask != 0
 * D. mask = mask << n
 * E. result |= (x & mask)
 */