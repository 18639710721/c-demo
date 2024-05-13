#include <stdio.h>

/* The next program uses the formula C=(5/9)(F-32)
to print the following table of Fahrenheit temperatures
and their centigrade or Celsius equivalents
*/

/*
 * 伪代码
 *      I
 *          华氏度
 *      P
 *          根据 C = (5/9)(F-32) 公式转换
 *      O
 *          摄氏度
 *
 * 过程描述
 *      设置 0到300的上下界, 每次增加20
 *      通过一个while循环实现
 *
 * */


/*
 * 变量
 *  int
 *  float
 *  double
 *  char  字符
 *
 * constant 常量
 *  整型
 *  实型
 *  字符型
 *  字符串
 *      \0表示字符串结束
 *
 *  类型 变量名 = 表达式
 *
 *  变量必须先定义后使用
 *  一条声明的语句可以定义多个变量
 *  要进行初始化，否则变量的值会是一个随机数
 *
 * 运算符
 *   + - * / % ++ --
 *   自动类型转换
 *      double > float > int > char
 *      强制类型转换
 *          (类型)表达式
 *   关系运算符
 *   逻辑运算符
 *      && || ! 与或非
 *   格式输出函数
 *      printf()
 *          %c  character  输出单个字符
 *          %s  string     输出一个字符串
 *          %d  decimal    十进制整数输出
 *          %f  float      小数形式输出浮点数
 *      scanf()
 *          中间的字符最好不用写,用printf做提示即可
 *
 * 控制流
 *      顺序
 *      分支
 *      循环
 *
 * */

void temperature_convert_while_version() {
    int Fahr, Celsius;
    int lower, upper, step;


    lower = 0;
    upper = 300;
    Fahr = lower;
    step = 20;

    while (Fahr <= upper) {
        // C=(5/9)(F-32)
        // 这里无法使用整型的 Celsius = (5/9) * (Fahr - 32)  因为 5/9 会等于 0
        Celsius = 5 * (Fahr - 32) / 9;
        printf("%d %d\n", Fahr, Celsius);
        Fahr += step;
    }

}

void temperature_convert_float_version() {
    double Fahr, Celsius;
    double lower, upper, step;


    lower = 0;
    upper = 300;
    Fahr = lower;
    step = 20;

    while (Fahr <= upper) {
        Celsius = (5.0 / 9.0) * (Fahr - 32.0);
        printf("%3.0f\t %6.1f\n", Fahr, Celsius);
        Fahr += step;
    }

}


void temperature_convert_for_version() {
    /* print Fahrenheit-Celsius table */
    int Fahr;
    for (Fahr = 0; Fahr <= 300; Fahr += 20) {
        printf("%d\t%6.1f\n", Fahr, (5.0 / 9.0) * (Fahr - 32.0));
    }
}

