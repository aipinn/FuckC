//
//  SequenceList.c
//  FuckC
//
//  Created by pinn on 2018/12/20.
//  Copyright © 2018 PINN. All rights reserved.
//

#include "SequenceList.h"

//---------
// 顺序表存储数据时，会提前申请一整块足够大小的物理空间，然后将数据依次存储起来，存储时做到数据元素之间不留一丝缝隙。

// 顺序表的初始化:

seqTable initTable() {
    seqTable t;
    t.head = (int *)malloc(SeqTableSize * sizeof(int));
    if (!t.head) {//初始化失败
        printf("linear table init error\n");
        exit(0);
    }
    t.length = 0;//空表
    t.size = SeqTableSize;
    return t;
}

// 输出表中的元素
void displayTable(seqTable t) {
    for (int i  = 0; i < t.length; i++) {
        printf("顺序表的元素:%d\n", t.head[i]);
    }
}

//在顺序表中插入元素
seqTable addTable(seqTable t, int element, int location) {
    //合法性判断
    if (location > t.length+1 || location < 1) {
        printf("插入位置有误");
    }
    //分配内存
    if (t.size == t.length) {
        t.head = (int *)realloc(t.head, (t.size+1)*sizeof(int));
        if(!t.head) {
            printf("分配内存错误");
            return t;
        }
        t.size++;
    }
    printf("目前表的长度:%d\n", t.size);
    //移动插入位置之后的元素
    //注意:后移的顺序必须是倒序
    for (int i = t.size; i > location; i--) {
        t.head[i] = t.head[i-1];
    }
    //插入元素
    t.head[location] = element;
    t.length++;
    return t;
}
