//
//  Link.c
//  FuckC
//
//  Created by pinn on 2018/12/23.
//  Copyright © 2018 PINN. All rights reserved.
//

#include "Link.h"
#include <stdlib.h>

// 创建一个{1,2,3,4}无头结点的链表
link *initLink() {
    link *p = NULL;//头指针
    link *temp = (link *)malloc(sizeof(link));//首元节点
    // 首元节点先初始化
    temp->elem = 1;
    temp->next = NULL;
    //头指针指向首元节点
    p = temp;
    
    //创建剩余节点,从第二个节点开始
    for (int i = 2; i < 5; i++) {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        
        temp->next = a;
        //temp每次都指向链表的最后一个节点
        temp = temp->next;//或者temp = a;
    }
    
    return p;
}
// 包含头结点
link *initLinkWithHeader(){
    link *p = (link *)malloc(sizeof(link));
    link *temp = p;
    for (int i = 1; i < 5; i++) {
        link *a = (link *)malloc(sizeof(link));
        a->elem = i;
        a->next = NULL;
        
        temp->next = a;
        temp = temp->next;
    }
    
    return p;
}

// 显示
void display(link *p,bool hasHeader){
    link *tmp = p;

    if (hasHeader) {
        tmp = tmp->next;
    } else {
        tmp = tmp;
    }
    while (tmp) {
        printf("%d", tmp->elem);
        tmp = tmp->next;
    }
    printf("\n");
}

/*
 以下操作均建立在包含头结点的链表{1,2,3,4}f的基础之上; 为了快速表达操作逻辑,省去了错误处理.
 */
/**
 链表插入元素
 */
link *insertLink(link *p,int element ,int location) {
    // 创建指向表的临时指针
    link *tmp = p;
    
    // 找到插入位置的上一个元素
    for (int i = 1; i < location; i++) {
        if (tmp->next == NULL) {
            printf("\n插入位置有误:%d\n",location);
            return p;
        }
        tmp = tmp->next;
    }
    // 创建插入节点
    link *a = (link *)malloc(sizeof(link));
    a->elem = element;
    // 插入元素
    a->next = tmp->next;
    tmp->next = a;
    return p;
}

/**
 链表删除元素
 */
link *deleteLink(link *p, int element) {
    //临时节点
    link *tmp = p;
    //找到删除节点的上一个节点
    //1.此处元素值刚好和位置值相同,不具有普遍性
//    for (int i = 1; i < element; i++) {
//        tmp = tmp->next;
//    }
    //2.先查找位置再删除
    int idx = selectLink(p, element);
    for (int i = 1; i < idx; i++) {
        tmp = tmp->next;
    }
    //删除节点
    link *del = tmp->next;
    tmp->next = tmp->next->next;
    //释放删除节点
    free(del);
    return p;
}
/**
 链表查找元素
 */
int selectLink(link *p, int element) {
    link *tmp = p;
    int i = 1;
    while (tmp->next) {
        tmp = tmp->next;
        if (tmp->elem == element) {
            return i;
        }
        i++;
    }
    return -1;
}
/**
 链表更新元素
 */
link *updateLink(link *p, int newEle, int oldEle) {
    link *tmp = p;
    int idx = selectLink(p, oldEle);
    for (int i = 1; i < idx; i++) {
        tmp = tmp->next;
    }
    tmp->next->elem = newEle;
    return p;
}

//反转链表
link *reversed_list(link *head) {
    
    //临时节点
    link *pReversedHead = NULL;
    link *pNode = head;
    link *pPrev = NULL;
    //顺序遍历链表
    while (pNode != NULL) {
        link *pNext = pNode->next;
        if (pNext == NULL) {
            pReversedHead = pNode;
        }
        pNode->next = pPrev;
        
        pPrev = pNode;
        pNode = pNext;
    }
    
    return pReversedHead;
}
