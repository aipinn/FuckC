//
//  main.c
//  FuckC
//
//  Created by pinn on 2018/11/28.
//  Copyright © 2018 PINN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "SequenceList.h"

#define OK    1
#define ERROR 0

typedef char ElementType;
typedef int  Status;
// 双向链表
typedef struct DualNode {
    ElementType data;
    struct DualNode *prior;
    struct DualNode *next;
} DualNode, *DuLinkList;

Status InitList(DuLinkList *L) {
    DualNode *p, *q;
    *L = (DuLinkList)malloc(sizeof(DualNode));
    if (!(*L)) {
        return ERROR;
    }
    (*L)->next = (*L)->prior = NULL;
    p = (*L);
    for (int i = 0; i < 26; i++) {
        q = (DualNode *)malloc(sizeof(DualNode));
        if (!q) {
            return ERROR;
        }
        q->data = 'A' + i; //q->data = 65
        q->prior = p;
        q->next = p->next;
        p->next = q;
        p = q;
    }
    p->next = (*L)->next;
    (*L)->next->prior = p;
    return OK;
}
void Cacsar(DuLinkList *L, int i) {
    if (i > 0) {
        do {
            (*L) = (*L)->next;
        }while (--i);
    }
    if (i < 0) {
        do {
            (*L) = (*L)->next;
        }while (++i);
    }
}


int main(int argc, const char * argv[]) {
    
    int num = add(10, 20);
    printf("%d\n", num);
    
    DuLinkList L;
    int n;
    InitList(&L);
    printf("请输入数字:");
    scanf("%d", &n);
    Cacsar(&L, n);
    for (int i = 0; i < 26; i++) {
        L = L->next;
        printf("%c", L->data);
    }
    printf("\n");
    seqTable table = initTable();
    for (int i = 0; i < SeqTableSize; i++) {
        table.head[i] = i;
        table.length++;
    }
    displayTable(table);
    printf("--add---\n");
    seqTable new = addTable(table, 9, 2);
    displayTable(new);
    printf("table:%p\nnew:%p", table.head, new.head);
    return 0;
}
