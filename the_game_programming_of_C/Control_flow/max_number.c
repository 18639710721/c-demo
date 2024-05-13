#include <stdio.h>


void find_max_number() {
    float a, b, c, max_number;
    printf("请输入三个数a, b, c\n");
    scanf("%f\n%f\n%f", &a, &b, &c);

    // 这里如果只有一条statement可以不加 多条statement要加
    if (a > b)
        max_number = a;
    else
        max_number = a;

    if (max_number < c)
        max_number = c;

    printf("max_number=%f\n", max_number);

}