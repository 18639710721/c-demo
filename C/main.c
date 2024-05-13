#include<stdio.h>    // 标准输入输出库  预编译文件
#include<math.h>    // 包含 math 库
#include <stdlib.h>
#include <float.h>
#include <string.h>

// function prototypes
int my_func(int, int);


/*
# include 包含 <stdio.h> .h header 头文件
stdio standard 标准   i input 输入   o output  输出
这个文件可能包含一个输入输出的头文件
C99   C语言标准

我的第一个C语言程序  注释 不被编译器识别
    转义字符


1.基本数据类型
    01序列 二进制
        3  11   占用2个bit位
        15 1111 占用4个bit位

    8个bit位一个字节  2个字节等于一个字
    所以一个字表示16个bit位

    100Mbps  10MB/s
    8bit = 1 B
    1024B = 1kb
    1024kb = 1MB
    1024MB = 1GB
    1024GB = 1TB
    1024TB = 1PB

    64位操作系统

2.原码 补码 和反码
    怎么表示负数
    原码
        用4个bit位去保存数据
        可以用第一个bit位保存符号  1为负 0为正数
        取值范围 1111 到 0111(-7 ~ 7)
        原码处理加减法很麻烦比如
        1+(-1) = 0001 + 1001 怎么计算 计算机只知道1+1到进位
        所以引入反码

    反码
        正数的反码是其本身
        负数的反码是在其原码的基础上，符号位不变，其余各个位取反
        1+(-1) = 0001 + 1110 = 1111 取反 1000 => 0
        0000和1111都表示0 然而在实数中 零既不是正数也不是负数
        感觉还是不够合理

    补码
        正数的补码就是其本身
        负数的补码在其原码的基础上 符号位不变 其余各位取反 最后+1(在反码基础上+1)
        这里-0已经被消除了
        1+(-1) = 0001 + 1111(取反再加一) = (1)0000 => +0
        此刻4bit位能表示的范围是 -8~7(C使用的是补码)
        -0没有了 1000 表示-8

整数类型
    int
    long
    short
浮点类型 整数部分和小数部分不是固定的 而是浮动决定的(计组)
    float   单精度浮点
    double  多精度浮点
字符类型
    char
溢出的情况

    %d
    %s
    %f
    const 无法修改

    scanf 为啥要用&
    https://blog.csdn.net/qq_44017116/article/details/123159536
    字符数组

    如何用指针读取数组的值?
Basic C Concepts
    Compilation  编译
        map to the low-level machine instructions
    Variable Types
        1.declare the type of data
        2.Declaration must come before or simultaneously with assignment
        Characters
            ASCII
    Typecasting
    Typed Function
        1.You have to declare the type of data you plan to
        return from a function
            return type
                void
                int
        2.Declaring the "prototype" of a function allows
        you to use it before the function 's definition.

C Syntax and Control Flow

Pointers
    Address vs. Value

*/

/* windows 控制台支持显示 utf8 编码的中文字符 */
/*输入中文乱码的解决方案 https://zhuanlan.zhihu.com/p/531460693*/
void windows_cmd_support_utf8(void) {
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

// 实现一个具有刷屏功能的函数
void Refresh_screen() {
    while (1) {
        printf("刷屏幕了~ !");
    }
}

/*
计算机关机任务实现
I 用户输入正确口令
P 默认是120秒后关机 判断和预设密码是否相同
O 没有关机或者关机
*/

void computer_shutdown() {
    int password;
    system("shutdown -t 120 -s");    // 120秒后电脑关机
    printf("请输入正确的口令: ");
    scanf("%d", &password);            // scanf是干嘛用的 不是太理解  将输入的指令存到password里面嘛
    if (password == 123)
        system("shutdown -a");       // 相同时解除关机


}


void datatype_bytes() {
    /*
     打印每种数据类型对应的字节数 window 64位操作系统
     */
    printf("数据类型：int，存储大小：%llu字节、最小值：%d，最大值：%d\n",
           sizeof(int), INT_MIN, INT_MAX);
    printf("数据类型；short, 存储大小 %llu字节、最小值：%hd，最大值 %hd\n",
           sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("数据类型； long， 存储大小 %llu字节、最小值：%ld, 最大值 %ld\n",
           sizeof(long), LONG_MIN, LONG_MAX);
    printf("数据类型： float, 存储大小 %llu字节、最小值：%g，最大值 %g\n",
           sizeof(float), FLT_MIN, FLT_MAX);
    printf("数据类型： double, 存储大小 %llu字节、最小值：%lg，最大值 %lg\n",
           sizeof(double), DBL_MIN, DBL_MAX);
    printf("数据类型： char, 存储大小%llu字节\n", sizeof(char));

    printf("数据类型： int类型指针, 存储大小%llu\n", sizeof(int**));
}

void overflow() {
    int i = 33;
    while (1) {
        i = i * 222;
        printf("%d\n", i);
    }
}

void overflow_test() {
//    int a = 2147483647; // INT_MAX
    short a = 0;
//    printf("a = %d\n", a);
//    a = a + 1;
//    printf("a + 1 = %d\n", a);
//    a = a + 1;
//    printf("a  + 1 = %d\n", a);
    for (int i = 0; i < 65536; i++) {
        a = a  + 1;
        printf("a + 1 = %d\n", a);
    }
}


void print_allAscii() {
    /*
     打印所有的ascii码
     */
    int ASCII_character;
    for (ASCII_character = 0; ASCII_character < 127; ASCII_character++) {
        printf("%d, %c, \n", ASCII_character, ASCII_character);
    }
}


void simple_story() {
    char characterName[] = "Tom";
    int characterAge = 67;
    printf("There once was a man named %s.\n", characterName);
    printf("he was %d years old.\n", characterAge);
    printf("He really liked the name %s.\n", characterName);
    printf("but didi not like being %d. \n", characterAge);
}

// 通过函数参数中的指针修改外部变量的值
void swap(int *number_1, int *number_2) {
    int temp = *number_1;
    *number_1 = *number_2;
    *number_2 = temp;
//    printf("number1 = %d\t number2 = %d\n", number_1, number_2);   // 并没有发生交换
}

// 返回长度最长的字符串
char *strlong(char *str1, char *str2) {
    printf("str1 address = %p\n", &str1);
    printf("str2 address = %p\n", &str2);
    if (strlen(str1) >= strlen(str2)) {
        return str1;
    } else {
        return str2;
    }
}

// 内存管理

// 标准  int必须写return  主函数入口
// 告诉操作系统程序从哪里执行 main函数即函数的入口
int main() {
    windows_cmd_support_utf8();

    // printf 打印的是值?
//    printf("hello world\n");
//    printf("main=%p\n", &main);     // 函数地址
//    printf("main=%p\n", main);     // 函数地址
//    printf("printf=%p\n", printf);  // 函数地址
//    printf("hello world=%p\n", "hello world\n");  // 字符串地址

//    int age = 40;
//    double gpa = 3.6;
//    char grade[] = "A";      // 为啥这里是两个字节
//    char phrase[] = "fjakfjalkf";

    // 这是单行注释
//    printf("Hello World!\n");   // print 打印  format 格式化输出
//    double sqrt_num = sqrt(9);   // 使用math库
//    printf("sqrt_num %f\n", sqrt_num);
//    Refresh_screen();

//    computer_shutdown();

    datatype_bytes();

//    print_allAscii();
//    overflow();
//      overflow_test();
//    simple_story();

//    int a = 1, b = 10;
//    swap(&a, &b);
//    printf("a = %d\t b = %d", a, b);   // 并没有发生交换

//    返回长度最长的字符串
//    char str1[30], str2[30], *str;
//    gets(str1);
//    gets(str2);
//    str = strlong(str1, str2);
//    printf("str address = %p\n", str);
//    printf("Longer string: %s\n", str);


//    int* p = malloc(sizeof(int)); // 算出申请类型所需的字节长度
//    *p =12;
//    printf("%d\n", *p);  // 12

//    int* p = (int*) malloc(sizeof (int));

//    int* p = (int*) malloc(sizeof(*p));
//    if (p == NULL) {
//        printf("内存分配失败");
//    } else {
//        printf("内存分配成功");
//    }

//    int* p = (int*) malloc(sizeof(int) * 10); // 申请放置10个整数的内存
//    for (int i = 0; i < 10; i++){
//        p[i] = i * 5;
//        printf("%d\n", p[i]);
//    }

    // 动态数组
//    int* p = (int*) malloc(n * sizeof(int));

//    char* p = malloc(4);
//    strcpy(p, "abc");
//    printf("%s", p);

    // free()
//    int* p = (int*) malloc(sizeof(int));
//    *p = 12;
//    free(p);
//    printf("%d", *p);

//    double a, b;
//    scanf("%lf %lf", &a, &b);
//    printf("%lf", a + b);


    // overflow situation
    short a = 65536;
    printf("the value of a %d\n", a);

    int b = 4294967296;
    printf("the value of b %d", b);
    return 0;
}