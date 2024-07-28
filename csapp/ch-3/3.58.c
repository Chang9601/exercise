/*
 * long decode(long x, long y, long z);
 * 1 decode2:
 * 2   subq  %rdx, %rsi
 * 3   imulq %rsi, %rdi
 * 4   movq  %rsi, %rax
 * 5   salq  $63, %rax
 * 6   sarq  $63, %rax
 * 7   xorq  %rdi, %rax
 * 8   ret
 */
long decode2(long x, long y, long z)
{
  long out;

  y -= z;
  x *= y;
  out = y;
  out <<= 63;
  out >>= 63;
  out ^= x;

  return out;
}
