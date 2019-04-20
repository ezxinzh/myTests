/*
 * cycleQueue.h
 *
 *  Created on: Apr 12, 2019
 *      Author: ezxinzh
 */

#ifndef CYCLEQUEUE_CYCLEQUEUE_H_
#define CYCLEQUEUE_CYCLEQUEUE_H_

template<class T>
class SeqQueue{
    protected:
        T *element;
        int front,rear;
        int maxSize;
    public:
        SeqQueue(int sz=10){
            front=rear=0;
            maxSize=sz;
            element=new T[maxSize];
        }
        ~SeqQueue(){
            delete[] element;
        }
        bool EnQueue(const T& x){//���
            if(isFull()) return false;
            element[rear]=x;
            rear=(rear+1)%maxSize;
            return true;
        }
        bool DeQueue(T& x){//����
            if(isEmpty()) return false;
            x=element[front];
            front=(front+1)%maxSize;
            return true;
        }
        bool getFront(T& x){//��ȡ����Ԫ��
            if(isEmpty()) return false;
            x=element[front];
            return true;
        }
        void makeEmpty(){//�����ÿ�
            front=rear=0;
        }
        bool isEmpty()const{//�ж϶����Ƿ�Ϊ��
            return (rear==front)?true:false;
        }
        bool isFull()const{//�����Ƿ�Ϊ��
             return ((rear+1)%maxSize==front)?true:false;
        }
        int getSize()const{
            return (rear-front+maxSize)%maxSize;
        }
};



#endif /* CYCLEQUEUE_CYCLEQUEUE_H_ */
