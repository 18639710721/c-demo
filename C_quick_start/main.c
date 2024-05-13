#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>



void windows_cmd_support_utf8(void);
void draw_pig();
void narrate_story();
void constant_test();
void digits_test();
void input_test();
void array_test();
void basic_calculator();
void mad_libs_game();
void sayHi(char name[], int age);
void nest_function();
double cube(double number);
int max_two(int number1, int number2);
int max_three(int number1, int number2, int number3);
void better_calculator();
void struct_test();
void while_loop_test();
void for_loop_test();

        int main() {
    windows_cmd_support_utf8();
//    draw_pig();
//    narrate_story();
//    digits_test();
//    constant_test();

//    input_test();

//    array_test();
//    basic_calculator();
//    mad_libs_game();
//    nest_function();
//    printf("%f",  cube(27));
//    printf("%d", max_two(3, 5));
//    printf("%d", max_three(0, 0, 0));
//    better_calculator();
//    struct_test();
//    while_loop_test();
    for_loop_test();
    return 0;
}

/* windows 控制台支持显示 utf8 编码的中文字符 */
/*输入中文乱码的解决方案 https://zhuanlan.zhihu.com/p/531460693*/
void windows_cmd_support_utf8(void) {
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

void draw_pig() {
    // C program just executed a set of instructions.
    // the order of exe instruction
    printf("/____|\n");   // semicolon is the terminate of statement.
    printf("    /|\n");
    printf("   / |\n");
    printf("  /  |\n");
    printf(" /   |\n");
}

/*
 variable is a container where store some data   为什么变量只是内存地址的别名 alias
 1. easier to keep track of and manage all the data
 2. modify the value of variable
 */
void narrate_story() {
    // 替换文本中变换的数据
    char characterName[] = "Tom";  // string
    int characterAge = 67;
    printf("There once was a man name %s\n", characterName);   // %s placeholder
    printf("he was %d years old.\n", characterAge);

    characterAge = 32;   // modify the value of variable
    printf("He really liked the name %s\n", characterName);
    printf("but did not like being %d\n", characterAge);

}

// data type
void data_type_test() {
    int age = 40;
    double gpa = 3.6;
    char grade = 'A';
    char phrase[] = "test"; // 这是个常量 不可修改

}

// digits test

void digits_test() {
    printf("%f\n", 5 + 5.5);  // 和浮点数相加会变成浮点数
    printf("%f\n", 5 / 4.0 );
    printf("%f\n", pow(2, 8));
    printf("%f\n", sqrt(36));
    printf("%f\n", ceil(3.6666));
    printf("%f\n", floor(3.666));
}

/* comment
C 语言的编译器会忽略注释
1. 解释程序的关键内容
2。把已有的代码注释 测试程序运行情况
*/


/* constant variable
1. constant variable can't be modify but a constant could
 refer to  read-only variable 常量不可以被修改但是能被引用 默认使用大写字母
2. print的字符串和参数都是常量
*/
void constant_test() {
    const int FAV_NUM = 5;
    printf("%d\n", FAV_NUM);
//    FAV_NUM = 8;    // assignment of read-only variable 'FAV_NUM'
    printf("%d", FAV_NUM);

    printf("Hello");
    printf("%d", 90);
}

// input

void input_test() {
    // age GPA grade name25

//    double gpa;
//    printf("Enter your GPA: ");
//    scanf_s("%lf", &gpa);
//    printf("Your age is %lf", gpa);

//    char grade;
//    printf("Enter your grade: ");
//    scanf_s("%c", &grade);
//    printf("Your age is %c", grade);

    char name[20];
//    printf("Enter your name: ");
//    scanf("%s", name);
//    printf("Your name is %s", name);
    printf("Enter your name: ");
    fgets(name, 20, stdin);   // 这里的\n也输入进去了，离谱
    printf("Your name is %s", name);
}

/* array
 Array is used to define a container that store any
 number of values.

 index at 0
 */

void array_test() {
    int luckyNumber[] = {4, 8, 15, 16, 23, 48};
    int badNumber[10];
    char phrase[20] = "Array";  // string 本质上是 array of characters 字符数组
    luckyNumber[1] = 115;
    printf("%d\n",luckyNumber[1]);

    badNumber[1] = 80;
    badNumber[0] = 90;
    printf("%d\n", badNumber[1]);

}

void basic_calculator() {
    double num1, num2;

    printf("Enter the first number: ");
    scanf_s("%lf", &num1);

    printf("Enter the second number: ");
    scanf_s("%lf", &num2);

    printf("the result is %lf", num1 + num2);

}

void mad_libs_game() {

    char color[20];
    char pluralNoun[20];
    char celebrity_f[20];
    char celebrity_l[20];

    printf("Enter a color: ");
    scanf("%s", color);
    printf("Enter a plural noun: ");
    scanf("%s", pluralNoun);
    printf("enter the celebrity: ");
    scanf("%s%s", celebrity_f, celebrity_l);  // 默认两个参数之间是空格

    printf("Roses are %s\n", color);
    printf("%s are blue\n", pluralNoun);
    printf("I love %s %s\n", celebrity_f, celebrity_l);
}

// function

void sayHi(char name[], int age) {
    printf("Hello %s, your are %d\n", name, age);
}

void nest_function() {
    // 函数调用栈 后进先出
    printf("top\n");
    sayHi("Mike", 40);
    sayHi("Tom", 23);
    sayHi("Oscar", 70);
    printf("bottom\n");
}

// return statement  return value 给调用者
double cube(double number) {
   return number * number * number;
}

// if statement  && || !
int max_two(int number1, int number2) {
    int result;
    if (number1 > number2) {
        result = number1;
    } else {
        result = number2;
    }
    return result;
}

int max_three(int number1, int number2, int number3) {
    int result;
    if (number1 >= number2 && number1 >= number3) {
        result = number1;
    } else if (number2 >= number1 && number2 >= number3) {
        result = number2;
    } else {
        result = number3;
    }

    return result;
}

void better_calculator() {
    double  num1, num2;
    char op;

    printf("Enter the number one: ");
    scanf_s("%lf", &num1);
    printf("Enter the operator");
    scanf_s(" %c", &op);
    printf("Enter the number two");
    scanf_s("%lf", &num2);

    if (op == '+') {
        printf("%lf", num1 + num2);
    } else if (op == '-') {
        printf("%lf", num1 - num2);
    } else if (op == '*') {
        printf("%lf", num1 * num2);
    } else if (op == '/') {
        printf("%lf", num1 / num2);
    } else {
        printf("invalid input");
    }
}

/*
 struct 相当于真实世界数据的模板

 */

void struct_test() {
    struct Student {
        char name[50];
        char major[50];
        int age;
        double gpa;
    };

    struct Student student1;
    student1.age = 22;
    student1.gpa = 3.2;
    strcpy(student1.name, "Jim");  // 字符数组不能之间传 所以用函数
    strcpy(student1.major, "Business");

    struct Student student2;
    student2.age = 20;
    student2.gpa = 2.5;
    strcpy(student2.name, "Pam");
    strcpy(student2.major, "Art");

    printf_s("%s\n", student2.name);
    printf_s("%s\n", student2.major);
    printf_s("%d\n", student2.age);

}

/*
 infinite loop
 */
void while_loop_test() {
    int index = 1;
    while (index <= 5) {
        printf("%d\n", index);
        index++;
    }
}

void for_loop_test() {
    for(int i = 0; i < 5; i++) {
        printf("%d\n", i);
    }

    int luckyNumbers[] = {3, 8, 1,15, 16, 23, 42};

    for (int i = 0; i < sizeof(luckyNumbers) / sizeof(luckyNumbers[0]); i++) {
        printf("%d\n", luckyNumbers[i]);
    }

}