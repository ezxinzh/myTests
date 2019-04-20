/*
 * main.cpp
 *
 *  Created on: Apr 11, 2019
 *      Author: root
 */
#include "singleList/singleList.h"
//#include "dubleList/"
#include "stack/linkStack.h"
#include "linkQueue/linkQueue.h"
#include "binaryTree/binaryTree.h"

#include <stdio.h>
#include <iostream>
#include <mysql/mysql.h>

using namespace std;

int main(int argc, char *argv[])
{
    //===================================singleList test
    if(0)
    {
        listNode * head;
        head = NULL;
        int arr[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45};
        int len = sizeof(arr)/sizeof(int);
        printf("======len=%d\n", len);
    //    initList(head);
        createListHead(head, arr, len);
    //    for(int i=0; i<(sizeof(arr)/sizeof(int)); i++)
    //    {
    //        insertList(head, i+1, arr[i]);
    //    }
    //    printf("======%d\n", head->next_->data_);
        traverseList(head);
        deleteList(head, 4);
        traverseList(head);
        insertList(head, 4, 2);
        traverseList(head);
    }

    //===================================linkStack test
    if(0)
    {
        linkStack myLinkStack;
        myLinkStack.init();

        int arr[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45, 62, 88};
        int len = sizeof(arr)/sizeof(int);
        for(int i=0; i<len; i++)
        {
            if(!myLinkStack.push(arr[i]))
                printf("======linkStack push failed!\n");
        }

        int topData;
        myLinkStack.getTop(topData);
        printf("======top data:%d\n", topData);
        printf("======stack len:%d\n", myLinkStack.Len());

        int data;
        printf("======pop:");
        while(!myLinkStack.isEmpty())
        {
            if(!myLinkStack.pop(data))
            {
                printf("======pop failed!\n");
                return -1;
            }
            printf("%d ", data);
        }
        printf("\n");
        printf("======stack len:%d\n", myLinkStack.Len());
    }

    //===================================linkQueue test
    if(0)
    {
        linkQueue myQueue;
        int arr[] = {6, 8, 16, 2, 34, 56, 7, 10, 22, 45, 62, 88};
        int len = sizeof(arr)/sizeof(int);
        initQueue(myQueue);
        for(int i=0; i<len; i++)
        {
            enQueue(myQueue, arr[i]);
        }
        myDisplay(myQueue);

        int data;
        getQueueHead(myQueue, data);
        printf("======queueHead data:%d\n", data);
        printf("======queue len:%d\n", queueLen(myQueue));

        printf("======dequeue:");
        while(!isQueueEmpty(myQueue))
        {
            deQueue(myQueue, data);
            printf("%d ", data);
        }
        printf("\n");
    }

    //===================================binaryTree test
    /*
     *                 10
     *              6       14
     *           4     8  12    16
     * */
    if(0)
    {
        treeNode_t *root;
        createTree(root);

        preOderTraverse(root);
        printf("\n");
        midOderTraverse(root);
        printf("\n");
        postOderTraverse(root);
        printf("\n");
        levelOderTravese(root);
    }

    //===================================mysql test
    if(1)
    {
        MYSQL mysql_;
        mysql_init(&mysql_);
        if(mysql_real_connect(&mysql_, "127.0.0.1", "root", "zaq1XSW2", "radio", 3306, NULL, 0))
        {
            if(mysql_query(&mysql_, "insert into radio_info values('12346', 3, 'abnormal')") != 0)
            {
                printf("mysql_real_query failed: %s\n", mysql_error(&mysql_));
                exit(0);
            }
            mysql_close(&mysql_);
            exit(0);
        }
        printf("mysql_real_mysql_ect failed: %s\n", mysql_error(&mysql_));
    }

    return 0;
}



