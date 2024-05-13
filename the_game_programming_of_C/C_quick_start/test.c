#include <stdio.h>

void test_basic() {
    double x1;
    double x2, x3;

    // 这里的char不知道为啥有问题 这里是ASCII码
    // char 必须是 ''   字符串才是""
    char c1, c2, c3;
    int x;
    c1 = 'a';
    c2 = 'b';
    c3 = 'A';

    x = c3 - c1;     // 大小写字母之间差了32
    printf("%d\n", c1);
    printf("%d\n", x);

    c2 = c2 + x;    // 转换成大写的B
    printf("%c\n", c2);

    x1 = 1;
    x1 = 2;

    x2 = x1 + 1;
    x3 = x1 + x2;



    printf("%f\n", x1);


}

void variable_assignment() {
    int number1, number2;

    number1 = 25;
    number2 = 23;

    number1 = number2;
}

// 算术运算符
void program_one() {
    int d;
    d = 1 / 3 * 3.0;  // 整数除法是舍掉小数部分的
    printf("d=%d\n", d);
}

void program_two() {
    int d;
    d = 1.0/3*3;
    printf("d=%d\n", d);
}

void program_three() {
    int d;
    d = 1*3/3;
    printf("d=%d\n", d);
}

// 强制类型转换
void cast() {
    int x = 10;
    float y;
    y = (float) x;
    printf("y=%f\n", y);

    float a, b;
    a = 3.5;
    b = 4.3;
    float c = (int)a;

    printf("c=%f\n",c);
}

// 关系运算符
void relational_operators() {
    printf("%d\n", 6 < 9);
    printf("%d\n", 3 == 5);
    printf("%d\n", 3 != 5);

}

// 输入输出函数
void format_test() {
    char char1 = 'U';
    char char2 = 'K';
    char char3 = 'M';
    printf("%c %c %c\n", char1, char2, char3);

    int a = 2;
    scanf("%d", &a);   // 为啥这里要用&取地址
    printf("%d\n", a);
}

void scanf_test() {
    printf("Key-in a character and a number: \n");
    char character;
    int num;
    scanf("%c\n%d", &character, &num);
    printf("Character: %c\n", character);
    printf("Number: %d\n", num);
}

void data_input() {
    int day, month, year;
    printf("请输入日月年: \n");
    scanf("%d\n%d\n%d", &day, &month, &year);
    printf("Day: %d, Month: %d, Year: %d\n", day, month, year);

}