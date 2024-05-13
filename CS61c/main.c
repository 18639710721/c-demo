#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define REPEAT 5



/*

Structs
    Way of defining compound data types
    A structured group of variables, possibly including other structs

    Align

union

Memory management
    Manual(malloc free)


#define

main
    int argc
        argument count
    argv
        a list pointing to strings

Variable Declarations

True || False
    0(integer)
    NULL(a special kind of pointer)
    其他都为真

Control Flow
    if-else
    while
    for
    switch
        break

Address vs. Value
    A pointer is a variable that contains an address.
    1. int *x;
        Declare variable x as the address of an int
    2. x = &y;
        Assigns address of y to x
        & called the "address operator" oin this context
    3. z = *x;
        Assigns the value at address in x to z
        * called the “dereference operator” in this context

Pointers and Parameter Passing
    Java and C pass parameters "by value"
        Procedure/function/method get a copy of
        the parameter, so changing the copy does not
        change the original.


Operator Precedence
    Dot
    arrow

    prefix(++p) takes effect immediately
    postfix/suffix(p++) take effect last

Array
    Modern machines are byte-addressable
    so the addresses are in bytes  所以地址以字节为单位
    64位 8个字节
    short/int/character pointer  word alignment 字对齐
    一个word是4个字节
    sizeof() operator
    为啥要 Struct Alignment
        感觉从小到大写 尽量把相同类型的写到一起

    bound  segmentation faults && bus errors

    string
        A string in C is just an array of characters
        null terminator

    数组
        一组被保存在连续存储空间中, 并且具有相同类型的数据元素集合
        Random Access 随机访问
            可以用相等的时间访问到一组数据中的任意一个元素
        为啥索引是从0开始的  zero-base indexing 从零开始索引
            base_address + index * data_size

    Pointer Arithmetic
        后缀运算符 从左到右   优先级高
        一元运算符 ++ -- * 从右到左
        ()


CS61C
实战
    数独游戏
    植物大战僵尸

*/

// function prototypes
int my_func(int, int);
void sayHello();
char *foo ();
void addOne(int *);     // 这里将传copy和传引用进行比较
//void addOne(int);
void string_examples();
void pointer_Arithmetic();
void pointer_question();
void increment_and_Dereference();


void windows_cmd_support_utf8(void);



int main(int argc, char *argv[]) {
    windows_cmd_support_utf8();
//    printf("%d",my_func(2, 3));

    // 为啥这里必须定义在main函数里面
    typedef struct {
        int lengthInSeconds;
        int yearRecorded;
    } Song;

    Song song1;

    song1.lengthInSeconds = 213;
    song1.yearRecorded = 1994;

    Song song2;

    song2.lengthInSeconds = 213;
    song2.yearRecorded = 1994;

//    printf("\n%d\n", song2.yearRecorded);

    // sample C code
//    int i;
//    int n = 5;
//    for (i = 0; i < REPEAT; i = i + 1){
//        printf("Hello, world\n");
//    }

    // 为什么这里只输入了一个字符
//    printf("%c",  *foo());

    // a copy
//    int y = 3;
//    addOne(y);
//    printf("函数外部y的值为%d", y);
//    return 0;

    // pass by reference
    int y = 3;
    addOne(&y);     // 这里是取址给指针变量嘛
    printf("函数外部y的值为%d\n", y);


    int * p;
    printf("64位机器指针变量的字节是 %llu\n", sizeof(p));

    // struct Alignment
    struct hello {
        int a;
        char b;
        short c;
        char *d;
        char e;
    };
    struct hello hello;
    struct hello_copy {
        int a;
        char b;
        char e;
        short c;
        char *d;
    };
    struct hello_copy hello_copy;

    printf("%d\n", sizeof(hello));
    printf("%d\n", sizeof(hello_copy));

//    string_examples();

    pointer_Arithmetic();
//    pointer_question();

    int data[5] = {1, 2, 3, 4, 5};
    printf("0x%p\n", &data);     // int是四个字节
    printf("0x%p\n", &data[1]);
    printf("0x%p\n", &data[2]);
    printf("0x%p\n", &data[3]);
    printf("0x%p\n", &data[4]);
    printf("%d\n", sizeof(data[0]));
    // 数组名实际上是一个指向数组首元素的指针常量 ??
    int * data_p = data;    // 这里为啥不用&符号 数组名不是variable有关?
//    printf("0x%p\n", data_p);
//    for (int i = 0; i < 5; i++){
//        printf("%d\n", *data_p);   // 通过指针用* inderection dereference去访问对应内存的值
//        data_p++;
//    }

    // 通过指针去访问数据
    for (data_p = data; data_p <= (data + 4); data_p++) {
        printf("%d\n", *data_p);
    }

    // 当不知道数组大小时用while 这个代码不行 指针不知道读到了哪里的值
//    while (*data_p) {
//        printf("%d\n", *data_p);
//        data_p++;
//    }

    // *p++ return *p, then incremetns p
    // ++ binds to p before *, but takes effect last
    /*
     *  1. Evaluate *p = "h"
     *  2. Assignment c = "h"
     *  3. p++; p = 41
     *  4. c = *p; c = "i"
     *
     * */
//    char *test_p = "hi";
//    char c = *test_p++;
//    printf("%c %p\n", c, test_p);
//    c = *test_p;
//    printf("%c", c);


    increment_and_Dereference();
    return 0;
}


void windows_cmd_support_utf8(void)
{
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

// function definitions;
int my_func(int x, int y) {
    sayHello();
    return x + y;
}

void sayHello() {
    printf_s("Hello\n");
}

char *foo() {
    return "Hello World";
}

// a copy
//void addOne(int x) {
//  x = x + 1;
//  printf("在函数内部y的值为%d\n", x);
//}

// pass by reference
void addOne(int *x) {
    *x = *x + 1;      // 通过reference修改了外部的值
    printf("在函数内部y的值为%d\n", *x);
}


// String Examples
void string_examples() {
    char s1[10], s2[10],  s3[] = "hello", *s4="hello";
    strcpy(s1, "hi");
    strcpy(s2, "hi");

    printf("%d  %d\n",sizeof(s1), strlen(s1));
    printf("%d\n", s1==s2);  // point to different locations
    printf("%d\n", strcmp(s1, s2));
    printf("%d\n", strcmp(s1, s3));
    printf("%d\n", strcmp(s1, s4));


}

// 有问题
void pointer_Arithmetic() {
    int test[] = {10, 9, 8, 7,6};
    int *p;
    for (p = test; p < (test + sizeof(test) * 4); p++){
        printf("%d\n", *test);

    }

}

void pointer_question() {
    int A[] = {5, 10};
    int *p = A;

    printf("%u %d %d %d\n", p, *p, A[0], A[1]);
    p = p + 1;     // 指针 内存地址+1
    printf("%u %d %d %d\n", p, *p, A[0], A[1]);
    *p = *p + 1;    // 解引用 值+1
    printf("%u %d %d %d\n", p, *p, A[0], A[1]);
}

void increment_and_Dereference() {
    /*
     *  char c = (*p)++
     *  1.Evaluate *p = "b"
     *  2.Assign c = "b"
     *  3.(*p)++;   "b" -> 'c'
     *  4.c = *p; c = 'c'
     *
     *
     */
    char arr[] = "bye";
    char *p = arr;
    char c = (*p)++;
    c = *p;
    printf("%c\n", c);
    printf("%s", arr);
}

