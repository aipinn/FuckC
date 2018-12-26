//
//  StaticLink.c
//  FuckC
//
//  Created by pinn on 2018/12/25.
//  Copyright © 2018 PINN. All rights reserved.
//

#include "StaticLink.h"

/**
 备用链表
 */
void reserveArr(component *array) {
    for (int i = 0; i < maxSize; i++) {
        array[i].cur = i+1;
    }
    //备用链表的最后一个元素的游标值为0
    array[maxSize-1].cur = 0;
}
/**
 初始化静态链表
 提示，此代码创建了一个带有头节点的静态链表，因此最先输出的 ",2" 表示的是头节点，其首元节点（存储元素 1 的节点）在数组 array[2] 中。
 */
int initArr(component *array) {
    reserveArr(array);
    int body = mallocArr(array);
    //声明一个变量把它作为指针,指向链表的最后一个节点,此时链表为空所以和头结点重合
    int temp = body;
    
    for (int i = 1; i < 4; i++) {
        int j = mallocArr(array); //2,3,4
        array[temp].cur = j;//array[1].cur = 2,array[2].cur = 3,array[3].cur = 4,
        array[j].data = i;//array[2].data = 1,array[3].data = 2,array[4].data = 3
        temp = j;//2,3,4
    }
    //新的链表的最后一个节点的指针设置为0
    array[temp].cur = 0;//array[4].cur = 0,
    return body;
}
/**
 显示静态链表
 */
void displayArr(component *array, int body) {
    int temp = body;
    while (array[temp].cur) {
        printf("%d,%d ", array[temp].data, array[temp].cur);
        temp = array[temp].cur;
    }
    printf("%d,%d\n",array[temp].data,array[temp].cur);
}
/**
 从备用链表上摘下空闲节点
 */
int mallocArr(component *array) {
    int i = array[0].cur;
    if (array[0].cur) {
        array[0].cur = array[i].cur;
    }
    return i;
}
