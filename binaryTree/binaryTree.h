/*
 * binaryTree.h
 *
 *  Created on: Apr 12, 2019
 *      Author: root
 */

#ifndef BINARYTREE_BINARYTREE_H_
#define BINARYTREE_BINARYTREE_H_

struct treeNode_t
{
    int data_;
    struct treeNode_t *left_;
    struct treeNode_t *right_;
};

/*
 *                 10
 *              6       14
 *           4     8  12    16
 * */

void preOderTraverse(const treeNode_t *r);
void midOderTraverse(const treeNode_t *r);
void postOderTraverse(const treeNode_t *r);
void createTree(treeNode_t * &r);
void levelOderTravese(const treeNode_t *r);
bool isTreeEmpty(const treeNode_t *r);
int treeDepth(const treeNode_t *r);
void destroyTree(treeNode_t * &r);



#endif /* BINARYTREE_BINARYTREE_H_ */
