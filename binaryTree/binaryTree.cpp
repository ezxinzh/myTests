/*
 * binaryTree->cpp
 *
 *  Created on: Apr 12, 2019
 *      Author: root
 */
#include "binaryTree.h"
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "../linkQueue/linkQueue.h"
#include "../cycleQueue/cycleQueue.h"

using namespace std;

void preOderTraverse(const treeNode_t *r)
{
    if(r != NULL)
    {
        printf("%d ", r->data_);
        preOderTraverse(r->left_);
        preOderTraverse(r->right_);
    }
}

void midOderTraverse(const treeNode_t *r)
{
    if(r != NULL)
    {
        midOderTraverse(r->left_);
        printf("%d ", r->data_);
        midOderTraverse(r->right_);
    }
}

void postOderTraverse(const treeNode_t *r)
{
    if(r != NULL)
    {
        postOderTraverse(r->left_);
        postOderTraverse(r->right_);
        printf("%d ", r->data_);
    }
}

void createTree(treeNode_t * &r)
{
    treeNode_t *s1, *s2, *t1, *t2, *t3, *t4;
    r = (treeNode_t*)malloc(sizeof(treeNode_t));
    s1 = (treeNode_t*)malloc(sizeof(treeNode_t));
    s2 = (treeNode_t*)malloc(sizeof(treeNode_t));
    t1 = (treeNode_t*)malloc(sizeof(treeNode_t));
    t2 = (treeNode_t*)malloc(sizeof(treeNode_t));
    t3 = (treeNode_t*)malloc(sizeof(treeNode_t));
    t4 = (treeNode_t*)malloc(sizeof(treeNode_t));

    r->data_ = 10;
    s1->data_ = 6;s2->data_ = 14;
    t1->data_ = 4;t2->data_ = 8;t3->data_ = 12;t4->data_ = 16;

    r->left_ = s1;r->right_ = s2;
    s1->left_ = t1;s1->right_ = t2;s2->left_ = t3;s2->right_ = t4;
    t1->left_ = NULL;t1->right_ = NULL;t2->left_ = NULL;t2->right_ = NULL;
    t3->left_ = NULL;t3->right_ = NULL;t4->left_ = NULL;t4->right_ = NULL;
}

void levelOderTravese(const treeNode_t *r)
{
    SeqQueue<treeNode_t> lq(20);
    treeNode_t *p;

    if(r)
    {
        lq.EnQueue(*r);
        while(!lq.isEmpty())
        {
            lq.DeQueue(*p);
            printf("%d ", p->data_);

            if(p->left_)
                lq.EnQueue(*p->left_);
            if(p->right_)
                lq.EnQueue(*p->right_);
        }
    }
    printf("\n");
}

bool isTreeEmpty(const treeNode_t *r)
{
    return r == NULL;
}

int treeDepth(const treeNode_t *r)
{
    int lh, rh;
    if(!r)
        return 0;
    else
    {
        lh = treeDepth(r->left_);
        rh = treeDepth(r->right_);
        return lh>rh ? lh+1 : rh+1;
    }
}

void destroyTree(treeNode_t * &r)
{
    if(r)
    {
        destroyTree(r->left_);
        destroyTree(r->right_);
        free(r);
        r = NULL;
    }
}


