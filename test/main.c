#include<stdio.h>
#include<stdbool.h>

char *foo() {
    return "Hello World";
}

int main() {
    int a = 1;
    int b;
    int *p = &a;
    int **two_p = &p;
    int ***three_p = &two_p;
    *p = 5;
    **two_p = 10;
    ***three_p = 15;

    b = ***three_p;

    printf("%d\n", ***three_p);

//    printf("%d\n", a);
//    printf("%p\n", b);



    char *result = foo();
    for (int i = 0; result[i] != '\0'; i++) {
        putchar(result[i]); // 逐字符打印
    }

    putchar('\n'); // 打印换行符

    int *empty =  NULL;
    int number = 5;

    printf("%d\n", (bool) empty);
    printf("%d\n", (bool) number);

    return 0;
}
