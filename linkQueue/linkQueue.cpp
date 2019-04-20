/*
 * queue.cpp
 *
 *  Created on: Apr 12, 2019
 *      Author: root
 */

#include "../linkQueue/linkQueue.h"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

using namespace std;


void initQueue(linkQueue &q)
{
    q.front_ = q.rear_ = NULL;
}

int queueLen(const linkQueue &q)
{
    int i = 0;
    queueNode *p = q.front_;
    while(p->next_)
    {
        i++;
        p = p->next_;
    }
    return i;
}

bool enQueue(linkQueue &q, const int data)
{
    queueNode *t = (queueNode*)malloc(sizeof(queueNode));
    if(!t)
        return false;
    t->data_ = data;
    t->next_ = NULL;
    if(!q.front_)
        q.front_ = q.rear_ = t;
    else
    {
        q.rear_->next_ = t;
        q.rear_ = t;
    }
    return true;
}

bool deQueue(linkQueue &q, int &data)
{
    queueNode *p;
    if(!q.front_)      //empty linkQueue
        return false;
    p = q.front_;
    data = p->data_;
    q.front_ = q.front_->next_;
    if(!q.front_)
        q.rear_ = NULL;
    free(p);
    return true;
}

bool isQueueEmpty(const linkQueue &q)
{
    return q.front_ == NULL;
}

void destroyQueue(linkQueue &q)
{
    queueNode *p,*p1;
    p = q.front_;
    while(p)
    {
        p1 = p;
        p = p->next_;
        free(p1);
    }
    q.front_ = q.rear_ = NULL;
}

bool getQueueHead(const linkQueue &q, int &data)
{
    if(q.front_)
    {
        data = q.front_->data_;
        return true;
    }
    else
        return false;
}

void myDisplay(const linkQueue &q)
{
    queueNode *p;
    p = q.front_;
    while(p)
    {
        printf("%d ", p->data_);
        p = p->next_;
    }

    printf("\n");
}




