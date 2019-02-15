//
//  Link.h
//  FuckC
//
//  Created by pinn on 2018/12/23.
//  Copyright © 2018 PINN. All rights reserved.
//

#ifndef Link_h
#define Link_h

#include <stdio.h>
#include <stdbool.h>//C99标准
typedef struct Link {
    char elem;//数据域
    struct Link *next;//指针域,指向直接后继元素
}link;

/**
 链表的初始化
 */
link *initLink(void);
/**
 初始化包含头结点的链表
 */
link *initLinkWithHeader(void);
/**
 输出,hasHeader是否包含头结点
 */
void display(link *p, bool hasHeader);

/*
 以下操作均建立在包含头结点的链表{1,2,3,4}f的基础之上
 */
/**
 链表插入元素
 */
link *insertLink(link *p,int element ,int location);
/**
 链表删除元素
 */
link *deleteLink(link *p, int element);
/**
 链表查找元素
 */
int selectLink(link *p, int element);
/**
 链表更新元素
 */
link *updateLink(link *p, int newEle, int oldEle);
//反转链表
link *reversed_list(link *head);

#endif /* Link_h */
