/*
 * singleList.h
 *
 *  Created on: Apr 11, 2019
 *      Author: ezxinzh
 */

#ifndef SINGLELIST_SINGLELIST_H_
#define SINGLELIST_SINGLELIST_H_


struct listNode
{
    int data_;
    listNode * next_;
};

void initList(listNode * &L);
int listLen(listNode * L);
listNode* findList(listNode * L, int find);
bool insertList(listNode * &L, int index, int data);
bool deleteList(listNode * &L, int index);
int getList(listNode * L, int index);
void createListRear(listNode * &L, int arr[], int len);
void createListHead(listNode * &L, int arr[], int len);
void traverseList(listNode * L);
void destroyList(listNode * &L);


#endif /* SINGLELIST_SINGLELIST_H_ */
