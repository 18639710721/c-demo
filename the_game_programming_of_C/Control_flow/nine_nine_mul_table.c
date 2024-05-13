#include <stdio.h>

void nine_nine_mult_table() {
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            // 打印每一行 可以加3对齐
            printf("%3d  ", i * j);
        }
        // 每输出一行都要回车
        printf("\n");
    }
}

void nine_nine_table_teacher_version() {
    int i, j;
    printf("    |");
    for (i = 1; i <= 9; i++) {
        printf("%3d", i);
    }
    printf("\n----------------------------------");
    printf("\n");
    for (i = 1; i <= 9; i++) {
        printf("%3d", i);
        printf(" |");
        for (j = 1; j <= 9; j++) {
            // j控制每行中输出几列
            if (j <= i) {
                printf("%3d", i * j);
            }
        }
        printf("\n");
    }
}

// v1  一个9*9的乘法矩阵
//void nine_nine_table_teacher_version() {
//    int i, j;
//    for (i = 1; i <= 9; i++) {
//        for (j = 1; j <= 9; j++) {
//                printf("%3d", i * j);
//        }
//        printf("\n");
//    }
//}

// v2 通过观察矩阵把所有 j <= i 的情况输出
//void nine_nine_table_teacher_version() {
//    int i, j;
//    for (i = 1; i <= 9; i++) {
//        for (j = 1; j <= 9; j++) {
//            // j控制每行中输出几列
//            if (j <= i) {
//                printf("%3d", i * j);
//            }
//        }
//        printf("\n");
//    }
//}

// v3 添加行数
//void nine_nine_table_teacher_version() {
//    int i, j;
//    printf("    |");
//    for(i = 1; i <= 9; i++) {
//        printf("%3d", i);
//    }
//    printf("\n");
//    for (i = 1; i <= 9; i++) {
//        for (j = 1; j <= 9; j++) {
//            // j控制每行中输出几列
//            if (j <= i) {
//                printf("%3d", i * j);
//            }
//        }
//        printf("\n");
//    }
//}

// v4 添加列数
//void nine_nine_table_teacher_version() {
//    int i, j;
//    printf("    |");
//    for(i = 1; i <= 9; i++) {
//        printf("%3d", i);
//    }
//    printf("\n");
//    for (i = 1; i <= 9; i++) {
//        printf("%3d", i);
//        for (j = 1; j <= 9; j++) {
//            // j控制每行中输出几列
//            if (j <= i) {
//                printf("%3d", i * j);
//            }
//        }
//        printf("\n");
//    }
//}

// v5 添加线
//void nine_nine_table_teacher_version() {
//    int i, j;
//    printf("    |");
//    for(i = 1; i <= 9; i++) {
//        printf("%3d", i);
//    }
//    printf("\n----------------------------------");
//    printf("\n");
//    for (i = 1; i <= 9; i++) {
//        printf("%3d", i);
//        printf(" |");
//        for (j = 1; j <= 9; j++) {
//            // j控制每行中输出几列
//            if (j <= i) {
//                printf("%3d", i * j);
//            }
//        }
//        printf("\n");
//    }
//}
