# Problem 1

1. `_mm_load_si128` requires that the memory address passed to it is aligned on a 16-byte boundary，
`_mm_loadu_si128` no such requirement
2. `_mm_load_pd`  requires that the memory address passed to it is aligned on an 8-byte boundary.
`_mm_load_pd` no such requirement

# Problem 2

# Problem 3

1. O0 对函数调用会保留调用前后的 prologue 和 epilogue. O3省略不必要的

2. O3直接把循环结果作为immediate得出了,O0还在笨笨地跑循环

3. 再比如O0每次都要慢慢地把 a load store. O3优化后只有2次。且O3合并？了两个循环