/*
 * dubleList.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: root
 */
#include "dubleList.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


void initDuList(dubleNode * &L)
{
    L = (dubleNode*)malloc(sizeof(dubleNode));
    if(!L)
        exit(1);
    L->next_ = NULL;
    L->pre_ = NULL;
}

bool insertDuList(dubleNode * &L, int index, int data)
{
    dubleNode *p,*q,*s;
    p = L->next_;
    int i = 1;
    while(i<index-1 && p->next_)
    {
        p = p->next_;
        i++;
    }

    if(i != index-1)
        return false;
    s = (dubleNode*)malloc(sizeof(dubleNode));
    if(!s)
        exit(1);
    if(p->next_)
    {
        q = p->next_;
        s->pre_ = q->pre_;
        q->pre_->next_ = s;
        s->next_ = q;
        q->pre_ = s;
    }
    else
    {
        p->next_ = s;
        s->pre_ = p;
        s->next_ = NULL;
    }

    return true;
}
