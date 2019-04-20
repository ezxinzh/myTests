/*
 * queue.h
 *
 *  Created on: Apr 12, 2019
 *      Author: root
 */

#ifndef LINKQUEUE_LINKQUEUE_H_
#define LINKQUEUE_LINKQUEUE_H_
#include "../singleList//singleList.h"

typedef listNode queueNode;

struct linkQueue
{
    listNode *front_;
    listNode *rear_;
};

void initQueue(linkQueue &q);
int queueLen(const linkQueue &q);
bool enQueue(linkQueue &q, int data);
bool deQueue(linkQueue &q, int &data);
bool isQueueEmpty(const linkQueue &q);
void destroyQueue(linkQueue &q);
bool getQueueHead(const linkQueue &q, int &data);
void myDisplay(const linkQueue &q);



#endif /* LINKQUEUE_LINKQUEUE_H_ */
