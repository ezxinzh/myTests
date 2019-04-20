/*
 * singleList.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: ezxinzh
 */

#include "singleList.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void initList(listNode * &L)
{
    L = (listNode*)malloc(sizeof(listNode));
    if(!L)
        exit(1);
    L->next_ = NULL;
}

int listLen(listNode * L)
{
    int i = 0;
    listNode * pL = L->next_;
    while(L->next_ != NULL)
    {
        i++;
        pL = pL->next_;
    }
    return i;
}

listNode* findList(listNode * L, int find)
{
    listNode *pl = L->next_;
    while(pl && pl->data_ != find)
    {
        pl = pl->next_;
    }
    return pl;
}

bool insertList(listNode * &L, int index, int data)
{
    listNode *p;
    int i = 1;
    p = L->next_;
    while(i<index-1 && p->next_)
    {
        i++;
        p = p->next_;
    }

    if(i != index-1)
        return false;
    listNode *q = (listNode *)malloc(sizeof(listNode));
    q->data_ = data;
    q->next_ = p->next_;
    p->next_ = q;
    return true;
}

bool deleteList(listNode * &L, int index)
{
    listNode *p, *q;
    int i = 1;
    p = L->next_;
    while(i<index-1 && p->next_)
    {
        i++;
        p = p->next_;
    }

    if(i != index-1)
    {
        printf("======error\n");
        return false;
    }
    q = p->next_;
    p->next_ = q->next_;
    free(q);
    return true;
}

int getList(listNode * L, int index)
{
    listNode *p;
    p = L;
    int i=0;
    while(i<index && p->next_)
    {
        i++;
        p = p->next_;
    }

    if(i != index)
        return false;
    return p->data_;
}

void createListRear(listNode * &L, int arr[], int len)
{
    listNode *p, *q;
    L = (listNode*)malloc(sizeof(listNode));
    q = L;
    for(int i=0; i<len; i++)
    {
        p = (listNode*)malloc(sizeof(listNode));
        p->data_ = arr[i];
        q->next_ = p;
        q = p;
    }
    q->next_ = NULL;
}

void createListHead(listNode * &L, int arr[], int len)
{
    listNode *p;
    L = (listNode*)malloc(sizeof(listNode));
    L->next_ = NULL;
    for(int i=len-1; i>=0; i--)
    {
        p = (listNode*)malloc(sizeof(listNode));
        p->data_ = arr[i];
//        printf("======p->data_:%d\n", p->data_);
        p->next_ = L->next_;
        L->next_ = p;
    }
}

void traverseList(listNode * L)
{
    listNode *p;
    p = L->next_;
    while(p)
    {
        printf("%d ", p->data_);
        p = p->next_;
    }
    printf("\n");
}

void destroyList(listNode * &L)
{
    listNode *p, *q;
    p = L;
    while(p)
    {
        q = p;
        p = p->next_;
        free(q);
    }
    L = NULL;
}


