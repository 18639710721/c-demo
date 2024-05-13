#include <stdio.h>

/*
 * 1.打印一行row直接用for循环即可
 * 2.打印一列column一层for循环后面+\n即可
 *
 * 3.打印n行n列用两层for循环
 *      内层代表行数
 *      外层代表列数
 *
 * 4.打印三角星的也是用两层for循环
 *      内层代码每行打印的星号数量(根据列数去循环)
 *      外层代码列数
 *
 * */


void print_row_asterisk(int n) {
    /* 根据n来打印一行对应数量的asterisk号 */
    for (int i = 0; i < n; i++) {
        printf("*");
    }
}

void print_column_asterisk(int n) {
    /* 根据n来打印一列对应数量的asterisk号 */
    for (int i = 0; i < n; i++) {
        printf("*\n");
    }
}

void print_rectangle_asterisk(int n) {
    /* 根据n来打印n行n列的正方形asterisk号 */
//    for (int i = 0; i < 5; i++) {
//        printf("*");
//    }
//    printf("\n");
//
//    for (int i = 0; i < 5; i++) {
//        printf("*");
//    }
//    printf("\n");
//
//    for (int i = 0; i < 5; i++) {
//        printf("*");
//    }
//    printf("\n");
//
//    for (int i = 0; i < 5; i++) {
//        printf("*");
//    }
//    printf("\n");
//    for (int i = 0; i < 5; i++) {
//        printf("*");
//    }
//    printf("\n");

    for (int j = 0; j < n; j++) {
        for (int i = 0; i < n; i++) {
            printf("*");
        }
        printf("\n");
    }
}


void print_triangle_asterisk(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i+1; j++) {
            printf("*");
        }
        printf("\n");
    }

}