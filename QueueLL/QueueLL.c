#include"QueueLL.h"

Queue * initQueue(int val){
    return LLinit(val);
}

bool EnQueue(int val){
    if(head == NULL){
        LLinit(val);
    }else{
        insertAtTail(val);
        return true;
    }
}

int DeQueue(){
    if(head == NULL){
        printf("Queue is Empty");
        return 0;
    }else{
        int data = head->data;
        deleteHead();
        return data;
    }
}

int Front(){
    if(tail == NULL && head == NULL){
        printf("Stack is Empty");
        return 0;   
    }else if(head != NULL){
        return head->data;
    }
}

int End(){
    if(tail == NULL && head == NULL){
        printf("Stack is Empty");
        return 0;   
    }else if(tail != NULL){
        return tail->data;
    }
}

bool isEmpty(){
    return head == NULL;
}