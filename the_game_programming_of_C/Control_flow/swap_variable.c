#include <stdio.h>

// 通过函数参数中的指针修改外部变量的值
void swap(int *number_1, int *number_2) {
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
//    printf("number1 = %d\t number2 = %d\n", number_1, number_2);   // 并没有发生交换
}

// 在main函数中发生的交换
//	int temp;
//
//	temp = a;
//	a = b;
//	b = temp;