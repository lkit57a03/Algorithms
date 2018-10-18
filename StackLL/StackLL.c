#include"StackLL.h"

Stack * initStack(int val){
    return LLinit(val);
}

bool push(int val){
    if(head == NULL){
        LLinit(val);
    }else{
        insertAtTail(val);
        return true;
    }
}

int pop(){
    if(head == NULL){
        printf("Stack is Empty");
        return 0;
    }else{
        int data = tail->data;
        deleteTail();
        return data;
    }
}

int peek(){
    if(tail == NULL && head == NULL){
        printf("Stack is Empty");
        return 0;   
    }else if(head != NULL){
        return head->data;
    }else{
        return tail->data;
    }
}

bool isEmpty(){
    return head == NULL;
}