# Ex1

1. `.data` and `.word`: static data
    `.text`: code

2. output: 34 fib数列中的第九个数

3. 走到la t3, n 这一行结束 停下来检查t3的值：0x10000010（但是不太懂original code被拆成两行Basic code, t3的值还要加个8是何意呢）

4. 走到刚进函数 停下来修改t3的值：13，然后run
    答案：

# Ex2

1. k: t0

2. pointer to source: t1
    pointer to dest: t2

3. `loop:`

see git log

# Ex3

```cpp
main:
    t0 = 0;
    t1 = 4
main_loop:
    if (t0 = t1) {exit;}
    t3 = t0 * 4
    t4 = t2 + t3
    a0 = word 中的-6， -3， 5， 11

    after function squareSum, the return value is stored in a0

SquareSum:
    abs a0, a0
    add t0, x0 # t0 store sum

SquareSumLoop:
    beq a0, x0, SSLexit
    mul t1, a0, a0
    add t0, t0, t1
    j SquareSumLoop

SSLexit:
    mv a0, t0
```
