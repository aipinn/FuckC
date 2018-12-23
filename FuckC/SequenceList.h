//
//  SequenceList.h
//  FuckC
//
//  Created by pinn on 2018/12/20.
//  Copyright © 2018 PINN. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#define SeqTableSize 5
typedef struct Table {
    int *head;//表头,声明了一个长度不确定的数组,也叫动态数组
    int length;
    int size;
}seqTable;

#include <stdio.h>
#include <stdlib.h>

/**
 初始化顺序表
 */
seqTable initTable(void);
/**
 输出表
 */
void displayTable(seqTable t);
/**
 顺序表增加元素
 */
seqTable addTable(seqTable t, int element, int location);
/**
 顺序表删除元素
 */
seqTable deleteTable(seqTable t, int location);

/**
 查找元素
 */
int selectTable(seqTable t, int element);

/**
 修改元素
 */
seqTable updataTable(seqTable t,int oldEle ,int newEle);

#endif /* SequenceList_h */
