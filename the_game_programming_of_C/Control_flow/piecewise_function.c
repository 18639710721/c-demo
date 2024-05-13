#include <stdio.h>

void piecewise_function_test() {
    // 根据x的值输出y的值
    int x, y;
    scanf("%d", &x);

    if (x < 0)
        y = -1;
    else if (x == 0)
        y = 0;
    else
        y = 1;
    printf("x=%d\ty=%d\n", x, y);


}