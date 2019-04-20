/*
 * linkStack.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: root
 */
#include "linkStack.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

linkStack::linkStack()
{
    S_ = NULL;
}

linkStack::~linkStack()
{
    this->destroy();
}

void linkStack::init()
{
    S_ = NULL;
}

int linkStack::Len()
{
    int i=0;
    stackNode *p;
    p = S_;
    while(p)
    {
        i++;
        p = p->next_;
    }
    return i;
}

bool linkStack::push(int data)
{
    stackNode *p;
    p = (stackNode *)malloc(sizeof(stackNode));
    if(!p)
        return false;
    p->data_ = data;
    p->next_ = S_;
    S_ = p;
    return true;
}

bool linkStack::pop(int &data)
{
    stackNode *p;
    if(S_)
    {
        data = S_->data_;
        p = S_;
        S_ = S_->next_;
        free(p);
        return true;
    }

    return false;
}

bool linkStack::getTop(int &data)
{
    if(S_)
    {
        data = S_->data_;
        return true;
    }

    return false;
}

bool linkStack::isEmpty()
{
    if(S_)
        return false;
    else
        return true;
}

void linkStack::destroy()
{
    stackNode *p, *q;
    p = S_;
    while(p)
    {
        q = p;
        p = p->next_;
        free(q);
    }
    S_ = NULL;
}


