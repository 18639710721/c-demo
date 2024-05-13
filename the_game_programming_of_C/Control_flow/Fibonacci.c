#include <stdio.h>

/*
 * Fibonacci数列
 *      Fibonacci螺旋
 * 任何一个数字都等于前两项之和
 * */

void fibonacci_sequence() {
    int f1, f2, i;
    f1 = 1, f2 = 1;
    for (i = 1; i <= 20; i++) {
        printf("%d %d ", f1, f2);
        f1 = f1 + f2;
        f2 = f1 + f2;
    }
}