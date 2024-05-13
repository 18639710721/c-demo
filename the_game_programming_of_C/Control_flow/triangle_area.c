#include <math.h>
#include <stdio.h>

/*
 *  求三角形面积
 *  s = (a+b+c)/2
 *  area = sqrt(s(s-a)(s-b)(s-c)) 海伦秦九韶公式
 * */

//double triangle_area_test(double a, double b, double c) {
//    double area, s;
////    printf("请分别输入三边的长度");
////    scanf("%lf\n%lf\n%lf", &a, &b, &c);
//
//    s = (a + b + c) / 2;
//    area = sqrt(s * (s - a) * (s - b) * (s - c));
//    printf("a=%lf, b=%lf, c=%lf, s=%lf\n", a, b, c, s);
//    return area;
//}

// 改进程序 需要验证是否是一个三角形 即 a + b > c
void triangle_area_test(double a, double b, double c) {
    double area, s;
    if ((a + b > c) && (a + c > b) && (b + c > a)) {
        s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("a=%lf, b=%lf, c=%lf, s=%lf\n", a, b, c, s);
        printf("the area is %lf\n", area);
    } else {
        printf("Wrong input!\n");
    }

}