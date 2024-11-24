typedef struct {
  int x[A][B];
  long y;
} str1;

typedef struct {
  char array[B];
  int t;
  short s[A];
  long u;
} str2;

void setVal(str1 *p, str2 *q) {
  long v1 = q->t;
  long v2 = q->u;
  p->y = v1+v2;
}

/*
 * setVal:
 *   movslq  8(%rsi), %rax
 *   addq    32(%rsi), %rax
 *   movq    %rax, 184(%rdi)
 *   ret
 */

/*
 * 7 ≤ A ≤10, 5 ≤ B ≤ 8, 45 ≤ AB ≤ 46
 * A = 9
 * B = 5
 */