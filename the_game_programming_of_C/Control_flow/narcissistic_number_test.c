#include <stdio.h>


/*
 * 水仙花数
 * 三位数的各位数字立方和等于本身
 * 153 = 1 * 1 * 1 + 5 * 5 * 5 + 3 * 3 * 3
 * */

int cube(int num) {
    return num * num * num;
}

void narcissistic_number() {
    int units_digit, tens_digit, hundreds_digit, number;
    // 三位数
    for (number = 100; number < 1000; number++) {
        // 一个数字的p进制
        units_digit = number % 10;
        tens_digit = number % 100 / 10;
        hundreds_digit = number / 100;
        if (cube(units_digit) + cube(tens_digit) + cube(hundreds_digit) == number) {
            printf("narcissistic number is %d\n", number);
        }

    }

}

