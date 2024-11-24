/*
 * (gdb) x/6gx Ox4006f8
 * Ox4006f8: Ox00000000004005al Ox00000000004005c3
 * Ox400708: Ox00000000004005al Ox00000000004005aa
 * Ox400718: Ox00000000004005b2 Ox00000000004005bf
 * 
 * %rdi: x, %rsi: n
 * 0000000000400590 <switch_prob>:
 *   400590: 48 83 ee 3c            sub   $0x3c,%rsi
 *   400594: 48 83 fe 05            cmp   $0x5,%rsi
 *   400598: 77 29                  ja    4005c3 <switch_prob+Ox33>
 *   40059a: ff 24 f5 f8 06 40 00   jmpq  *Ox4006f8(,%rsi,8)
 *   4005a1: 48 8d 04 fd 00 00 00   lea   Ox0(,%rdi,8),%rax
 *   4005a8: 00                     
 *   4005a9: c3                     retq
 *   4005aa: 48 89 f8               mov   %rdi,%rax
 *   4005ad: 48 cl f8 03            sar   $0x3,%rax
 *   4005b1: c3                     retq           
 *   4005b2: 48 89 f8               mov   %rdi,%rax
 *   4005b5: 48 cl eO 04            shl   $0x4,%rax
 *   4005b9: 48 29 f8               sub   %rdi,%rax
 *   4005bc: 48 89 c7               mov   %rax,%rdi
 *   4005bf: 48 Of af ff            imul  %rdi,%rdi
 *   4005c3: 48 8d 47 4b            lea   Ox4b(%rdi),%rax
 *   4005c7: c3                     retq
 */
long switch_prob(long x, long n)
{
  /* 
   * cmp $0x5,%rsi -> [0,5]
   * sub $0x3c,%rsi -> [0,5] + 60(0x3c)
   * 
   * 4005al = 0 = 60
   * 4005c3 = 1(ja 4005c3 <switch_prob+0x33> = default)
   * 4005al = 2 = 62
   * 4005aa = 3 = 63
   * 4005b2 = 4 = 64
   * 4005bf = 5 = 65
   */
  long result = x;
  switch (n) {
    case 60:
    case 62:
      //result = x * 8;
      result *= 8;
      break;
    case 63:
      //result = x;
      result >>= 3;
      break;
    case 64:
      //result = x;
      result <<= 4;
      result -= x;
      x = result;
    case 65:
      x *= x;
    default:
      result = x + 75;
      break;
  }
  return result;
}