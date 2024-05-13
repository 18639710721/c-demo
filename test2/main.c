#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <math.h>

// Function Prototype
void windows_cmd_support_utf8(void);
void test_system_instruction(void);
void computer_shutdown(void);
void comic_pig();
void scroll_screen();
void transfer_fahr_to_celsius_while_version();
void transfer_fahr_to_celsius_for_version();
void transfer_fahr_to_celsius_second_version();
void transfer_fahr_to_celsius_symbolic_constants();
void rectangle_area();
void print_grade_table();
void pointer_test();
void increment(int* p);
void print_triangle_area();
void sizeof_test();
void array_test();



int main(void) {
    windows_cmd_support_utf8();
//    computer_shutdown();
//    comic_pig();
//    scroll_screen();
//    transfer_fahr_to_celsius_while_version();
//    transfer_fahr_to_celsius_for_version();
//    transfer_fahr_to_celsius_second_version();
//    transfer_fahr_to_celsius_symbolic_constants();
//    rectangle_area();
//     print_grade_table();
//        pointer_test();
//    print_triangle_area();
//    sizeof_test();
    array_test();
    return 0;
}

/* windows 控制台支持显示 utf8 编码的中文字符 */
/*输入中文乱码的解决方案 https://zhuanlan.zhihu.com/p/531460693*/
void windows_cmd_support_utf8(void) {
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}




void test_system_instruction(void) {
    system("dir");
    system("start notepad");
    system("systeminfo");
//    system("ping www.google.com");
    system("whoami");
    system("tasklist");
    system("taskkill /IM notepad.exe /F");  // 强制关闭所有记事本实例 很有用嘛 小子
}

void computer_shutdown(void) {
    /*
     * 1.如何设计如果输入错误口令就需要一直输入呢
     *      使用while true 死循环 利用 break 在条件成功后跳出
     * 2.如何限制用户的输入次数，而不是无穷呢
     *      更多的是一个逻辑的问题 思考问题步骤分解的不够清晰
     *      更多的需要考虑一个问题的边界条件
     */
    int default_password = 123;   // default password
    int user_input_password;
    int input_counter = 0 ;      // 用于输入次数统计 默认为0
    int input_chance = 3;        // 默认的输入机会为3
    system("shutdown -t 120 -s"); // -t time -s shutdown
    while (true) {
        printf("请输入正确的指令: ");    // Input
        scanf_s("%d", &user_input_password);
        if (default_password == user_input_password) {
            system("shutdown -a");  // -a abort to cause something to stop or fail before it begins or before it is complete
            printf("恭喜你, 成功阻止了电脑关机");
            break;

        } else {
            input_counter = input_counter + 1;
            printf_s("输入密码不对, 您还有%d次机会，\n"
                     "请输入正确的指令", input_chance - input_counter );
            if ((input_counter - input_chance) >= 0) {
                printf_s("您的机会已用尽");
                break;
            }
        }
    }

}

void comic_pig() {
    printf("  ^  ^  \n");
    printf(" ( o o ) \n");
    printf("  ( _ ) \n");
    printf("   | |  \n");
    printf("  (__|__) \n");

}

// Ctrl + c 可以终止命令行的死循环
void scroll_screen() {
    while (1) {
        printf_s("刷屏幕啦~! ");
    }
}

void transfer_fahr_to_celsius_while_version() {
    /* print Fahrenheit-Celsius table
        for fahr = 0, 20, ..., 300
        C = (5/9) (F - 32)         */

    int fahr, celsius;
    int start, end, step;


    start = 0;
    end = 300;
    step = 20;

    fahr = start;
    while (fahr<= end) {
        celsius = (5 * (fahr - 32)) / 9;
        printf("%d\t%d\n", fahr, celsius);
        fahr += step;
    }

}

void transfer_fahr_to_celsius_second_version() {
    /* 由于int 类型的不太准确 会发生截断
       所以修改为float类型 */
    float fahr, celsius;
    float start, end, step;


    start = 0;
    end = 300;
    step = 20;

    fahr = start;
    while (fahr<= end) {
        celsius = (5 * (fahr - 32)) / 9;
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr += step;
    }

}

void transfer_fahr_to_celsius_for_version() {
    /* print Fahrenheit-Celsius table
        for fahr = 0, 20, ..., 300
        C = (5/9) (F - 32)         */
    int fahr;
    for(fahr = 0; fahr < 300; fahr += 20) {
        printf("%3d%6.1f\n", fahr, (5.0 / 9.0 * (fahr - 32)));
    }
}

void transfer_fahr_to_celsius_symbolic_constants() {
    /* Don't use magic numbers, a #define line defines a symbolic
     name or symbolic constant to be a particular string of characters.
     */
#define LOWER 0
#define UPPER 300
#define STEP 20
    int fahr;
    for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
}

void rectangle_area() {
    double length, width, area;
    length = 3;
    width = 4;

    area = length * width;

    printf("%f", area);
}

void print_grade_table() {
    float math, computer_science, c_language;
    long student_num;
    char sex;
    int age;

    math = 98.5;
    computer_science = 98.5;
    c_language = 98.5;
    student_num = 201601;
    sex = 'M';
    age = 19;

    // 50 *
    printf_s("**************************************************\n");
    printf_s("* *               成绩单                       * *\n");
    printf_s("* ********************************************** *\n");
    printf_s("* *             姓  名：张煜                   * *\n");
    printf_s("* *             学  号：%ld                 * *\n", student_num);
    printf_s("* *             年  龄：%d                     * *\n",age );
    printf_s("* *             性  别：%c                      * *\n",sex);
    printf_s("* *             数  学：%.2f                  * *\n", math);
    printf_s("* *             计算机：%.2f                  * *\n",computer_science);
    printf_s("* *             C 语言：%.2f                  * *\n",c_language);
    printf_s("* ********************************************** *\n");
    printf_s("* ********************************************** *\n");

}

void increment(int* p) {
    *p = *p + 1;
}

void pointer_test() {
    int x = 1;
    char test = 'A';
    printf("x's address is %p\n", &x);
    printf("test's address is  %p\n",&test);

    increment(&x);
    printf("the value x is %d\n", x);

    // init
    int *p = NULL;
    int i;

    p = &i;
    *p = 13;
    printf("%d", i);

    short* j;

    j = (short* )0x1234;
    j = j + 1;
    printf("the address of j is %p", j);
}

// sizeof

void sizeof_test() {
    int x = sizeof(int);
    printf("%u\n", x);
    int i;
    printf("%llu\n", sizeof(i));
    printf("%llu", sizeof(3.14));
}

void print_triangle_area() {
    double a, b, c;  // 三角形的三边长
    double p;
    double area;

    a = 6;
    b = 8;
    c = 10;
    p = (a + b + c) / 2;
    area = sqrt(p * (p-a) * (p-b) * (p-c));

    printf("********************************\n");
    printf("**    此三角形面积为%.2f     **\n", area);
    printf("********************************\n");
}

void array_test() {
    int a[] = {22, 37, 3490};
    int arrLen = sizeof(a);
    int elementLen = sizeof(a[0]);
    printf("%p\n", a);
    printf("%p\n", a + 1);
    printf("%p\n", a + 2);
    printf("%d\n", arrLen);
    printf("%d\n", elementLen);
    printf("%llu", sizeof(a) / sizeof(a[0]));
}