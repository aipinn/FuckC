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
#include "Link.h"

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


//链表

void testLink(void) {
//    link *l = initLink();
//    display(l, false);
    link *l = initLinkWithHeader();
    display(l, true);
//    printf("---insert element--\n");
//    insertLink(l, 0, 1);
//    display(l, true);
//    printf("---delete element--\n");
    deleteLink(l, 3);
    display(l, true);
    printf("---select element--\n");
    int idx = selectLink(l, 3);
    printf("元素的位置:%d\n",idx);
//    printf("---update element--\n");
//    updateLink(l, -2, 2);
//    display(l, true);

}

void oneDualDirectionLink(void){
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
}

//顺序表
void testSeqList(void){
    printf("\n---init--\n");
    seqTable table = initTable();
    for (int i = 0; i < SeqTableSize; i++) {
        table.head[i] = i;
        table.length++;
    }
    displayTable(table);
    
    printf("--add--\n");
    addTable(table, 9, 0);
    displayTable(table);
    
    printf("--delete--\n");
    int loc;
    printf("请输入要删除的元素的位置:");
    scanf("%d", &loc);
    deleteTable(table, loc);
    displayTable(table);
    printf("---select---\n");
    int idx = selectTable(table, 9);
    printf("%d\n",idx);
    printf("---update--\n");
    updataTable(table, 3, 30);
    displayTable(table);
    
}


int main(int argc, const char * argv[]) {
    
    testLink();
    
    return 0;
}


