/*
 * linkStack.h
 *
 *  Created on: Apr 11, 2019
 *      Author: root
 */

#ifndef STACK_LINKSTACK_H_
#define STACK_LINKSTACK_H_

#include "../singleList/singleList.h"

typedef listNode stackNode;

class linkStack
{
public:
    linkStack();
    ~linkStack();

    void init();
    int Len();
    bool push(int data);
    bool pop(int &data);
    bool getTop(int &data);
    bool isEmpty();
    void destroy();
private:
    stackNode * S_;
};


#endif /* STACK_LINKSTACK_H_ */
