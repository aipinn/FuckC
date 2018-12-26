//
//  StaticLink.h
//  FuckC
//
//  Created by pinn on 2018/12/25.
//  Copyright © 2018 PINN. All rights reserved.
//

#ifndef StaticLink_h
#define StaticLink_h

#include <stdio.h>
#include <stdlib.h>
#endif /* StaticLink_h */

//通过 "数组+游标" 的方式存储具有线性关系数据的存储结构就是静态链表。

//静态链表中的节点
typedef struct {
    int data;//数据域
    int cur;//游标
}component;

//备用链表
//静态链表中，除了数据本身通过游标组成的链表外，还需要有一条连接各个空闲位置的链表，称为备用链表。
//备用链表的作用是回收数组中未使用或之前使用过（目前未使用）的存储空间，留待后期使用。
//通常，备用链表的表头位于数组下标为 0（a[0]） 的位置，而数据链表的表头位于数组下标为 1（a[1]）的位置。
#define maxSize 6
/**
 备用链表
 */
void reserveArr(component *array);
/**
 初始化静态链表
 */
int initArr(component *array);
/**
 显示静态链表
 */
void displayArr(component *array, int body);
/**
 从备用链表上摘下空闲节点
 */
int mallocArr(component *array);
