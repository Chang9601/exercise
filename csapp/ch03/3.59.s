# typedef __int128 int128_t;
#
# void store_prod(int128_t#dest, int64_t x, int64_t y)
# {
#  *dest = x# (int128_t) y;
# }
#
# %rdi: dest, %rsi: x, %rdx: y
store_prod:
  movq    %rdx, %rax     # %rax = y
  cqto                   # %rdx = sign_y (y의 부호)
  movq    %rsi, %rcx     # %rcx = x
  sarq    $63, %rcx      # %rcx = sign_x (x의 부호)
  imulq   %rax, %rcx     # %rcx = sign_x * y
  imulq   %rsi, %rdx     # %rdx = sign_y * x
  addq    %rdx, %rcx     # %rcx = sign_x * y + sign_y * x
  mulq    %rsi           # %rdx:%rax = x * y
  addq    %rcx, %rdx     # %rdx = x * y + sign_x * y + sign_y * x
  movq    %rax, (%rdi)   # (%rdi) = lower_x*y (값의 하위 64비트)
  movq    %rdx, 8(%rdi)  # 8(%rdi) = upper_x*Y (값의 상위 64비트)
  ret