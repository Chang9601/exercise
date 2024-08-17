union ele {
    struct {
        long *p;
        long y;
    } el;
    struct {
      long x;
      union ele *next;
    } e2;
};

void proc (union ele *up) {
   up->___________=*(        ) - ____________;
}
/*
 * void proc (union ele *up) 
 * %rdi: up
 * proc:
 *   movq   8(%rdi), %rax
 *   movq   (%rax), %rdx
 *   movq   (%rdx), %rdx
 *   subq   8(%rax), %rdx
 *   movq   %rdx, (%rdi)
 *   ret
 */

/*
 * A. e1.p: 0, e1.y:8, e2.x: 0, e2.next: 8 
 * B. 16 바이트
 * C. up->e2.x = *(up->e2.next->e1.p) - up->e1.y
 */

union u3 {
  char c;
  int i[2];
  double v;
};

        c i v
offset  0 0 0
size    8