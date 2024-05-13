#include <stdio.h>
#include <stdlib.h>

typedef struct node node;

/*
 1. 单个节点数据结构的定义
 2. 两个节点的串联
 3. 多个节点循环初始化
 4. 链表输出
 5. 删除结点
 */

void pointer_test() {
    struct node {
        int data;
        struct node *next;
    };

//    node *head;
//    struct node *p1, *p2;
//    p1 = (node *) malloc(sizeof(struct node));
//    (*p1).data = 1;
//
//    p2 = (node *) malloc(sizeof(struct node));
//    (*p2).data = 2;
//
//    p1 -> next = p2;
//
//    head = p1;
//    printf("%d", p1->data);

    struct node *head, *p1, *p2;
    head = NULL;
    for (int i = 1; i <= 5; i++) {
        p1 = (node *) malloc(sizeof (struct node));
        (*p1).data = i;
        if (head == NULL) {   // 链表为空, 则将该结点设置为表头
            head =  p1;
            p2 = p1;
        } else {      // 链表非空, 则将该结点加入链表的末尾
            p2 -> next = p1;
            p2 = p1;
        }
    }

    p2->next = NULL;

    // 删除数据为2的链表节点
    p1 = head;
    while (p1->data!=2) {
        p2 = p1;
        p1 = p1->next;
    }
    p2 -> next = p1 -> next;
    free(p1);

    // 输出链表数据
    struct node *p;
    p = head;
    printf("链表上各节点的数据为: \n");
    while (p!= NULL) {
        printf("%d\n", p->data);
        p = p->next;
    }
    printf("\n");

}

