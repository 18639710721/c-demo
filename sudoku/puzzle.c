#include "sudoku.h"
#include <stdio.h>
#include <stdlib.h>


// 返回一个int类型的二重指针
int ** createPuzzle() {
    // puzzle
    int **puzzle;
    // loop counters
    int i, j;
    int array[9][9] = {
            0, 1, 9, 0, 0, 2, 0, 0, 0,
            4, 7, 0, 6, 9, 0, 0, 0, 1,
            0, 0, 0, 4, 0, 0, 0, 9, 0,
            8, 9, 4, 5, 0, 7, 0, 0, 0,
            0, 0, 0, 0, 0, 0, 0, 0, 0,
            0, 0, 0, 2, 0, 1, 9, 5, 8,
            0, 5, 0, 0, 0, 6, 0, 0, 0,
            6, 0, 0, 0, 2, 8, 0, 7, 9,
            0, 0, 0, 1, 0, 0, 8, 6, 0,
    };

    puzzle = (int**)malloc(sizeof(int*)*9);    // int* 8bytes
    printf("%llu\n",sizeof(int*)*9);
    for (i = 0; i < 9; i++) {
        puzzle[i] = (int*) malloc(sizeof(int)*9);  // int 4bytes
        printf("%llu\n", sizeof(int) * 9);
        for (j = 0; j < 9; j++) {
            puzzle[i][j] = array[i][j];
        }
    }

    return puzzle;
}

void printPuzzle(int ** puzzle) {
    int i, j;

    printf("-------------------------------\n");
    for (i = 0; i < 9; i++) {
        printf("|");
        /* print each row */
        for (j = 0; j < 9; j++) {
            printf(" %d ", puzzle[i][j]);
            if (((j + 1) % 3 == 0)) {
                printf("|");
            }
        }
        printf("\n");
        if (((i + 1) % 3 == 0)) {
            printf("-------------------------------\n");
        }
    }


}

/*
 * 指针作为函数返回值是用来干嘛的?
 * 数组和指针有何关系
 * malloc申请内存的详细过程
 *
 * */
//int *createPuzzle() {
//    int *puzzle;
//    int i;
//    int array[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    puzzle = (int *) malloc(sizeof(int) * 9);
//    for (i = 0; i < 9; i++) {
//        puzzle[i] = array[i];
//    }
//
//    return puzzle;
//}
//
//void printPuzzle(int *puzzle) {
//    for (int i = 0; i < 9; i++) {
//        printf("%d  ",puzzle[i]);
//    }
//}