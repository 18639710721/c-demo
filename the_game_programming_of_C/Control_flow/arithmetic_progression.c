#include <stdio.h>

int arithmetic_progression_sum(int boundary) {
    // 求和从1到boundary包括boundary这个数字
    int i, sum = 0;
    for (i = 1; i <= boundary; i++) {
        sum = sum + i;
    }

    return sum;
}

int arithmetic_progression_sum_math(int boundary) {
    return ((1 + boundary) * boundary) / 2;
}

int self_mul(int num) {
    int sum = 0;
    for (int i = 1; i <=num; i++) {
        sum += i * i;
    }
    return sum;
}

int arithmetic_progression_sum_while_version(int boundary) {
    int iter_num = 1;
    int sum = 0;
    while (iter_num <= boundary) {
        sum += iter_num;
        iter_num++;
    }
    return sum;
}

void arbitrary_five_number_sum() {
    /* 这个程序有bug啊 */
    int counter = 1, sum = 0, n;
    while (counter < 6) {
        scanf("%d", &n);
        sum = sum + n;
        counter++;

    }
    printf("sum=%d\n", sum);

}