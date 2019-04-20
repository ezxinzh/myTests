/*
 * dubleList.h
 *
 *  Created on: Apr 11, 2019
 *      Author: root
 */

#ifndef DUBLELIST_DUBLELIST_H_
#define DUBLELIST_DUBLELIST_H_

struct dubleNode
{
    int data_;
    dubleNode * pre_;
    dubleNode * next_;
};

void initDuList(dubleNode * &L);
bool insertDuList(dubleNode * &L, int index, int data);
bool deleteDuList(dubleNode * &L, int index);



#endif /* DUBLELIST_DUBLELIST_H_ */
