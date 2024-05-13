
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void windows_cmd_support_utf8(void) {
#ifdef WIN32
    system("chcp 65001 & cls"); //cls 用来清除 chcp 的输出
#endif
}

void showDice(int* dice,size_t num) {
    printf("\t-----------\n");
    printf("       /          /|\n");
    printf("      /    %d     / |\n",dice[0]);
    printf("     /          /  |\n");
    printf("     -----------   |\n");
    printf("     |         | %d |\n",7-dice[2]);
    printf("  %d  |    %d    |   /\n", dice[2],dice[1]);
    printf("     |         |  /\n");
    printf("     |         | /\n");
    printf("     -----------/\n");
    printf("	  %d\n", 7-dice[0]);
    printf("\n");
    return;
}

int main() {
    windows_cmd_support_utf8();
    int data[6][4] = {
            {2, 3, 5, 4},
            {6, 3, 1, 4},
            {1, 2, 6, 5},
            {1, 5, 6, 2},
            {1, 3, 6, 4},
            {2, 4, 5, 3} };
    int dice[3];
    while (1)
    {
        printf("\n\n==================================\n");
        unsigned int value = 0;
        srand(time(NULL));
        value = rand() % 6; //取值范围是0~5

        printf("掷到的点数为:%d\n", value + 1);			//因为取值范围是0~5，所以需要加一个一
        dice[0] = value + 1;							//top side

        unsigned int value_2 = 0;
        value_2 = rand() % 4;							//找环的起点，取值范围是0~3，四个数中随机取一个


        dice[1] = data[value][value_2];					//front side
        dice[2] = data[value][(value_2 + 1) % 4];		//left side
        showDice(dice, 3);
        printf("再扔一次？\n");
        getchar();
    }
    return 0;
}
