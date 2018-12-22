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

/*
 初始化顺序表
 */
seqTable initTable(void);
/*
 输出表
 */
void displayTable(seqTable t);

seqTable addTable(seqTable t, int element, int location);

#endif /* SequenceList_h */
