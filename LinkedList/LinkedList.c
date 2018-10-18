#include "LinkedList.h"


Node * createNode(int val){
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

Node * init(int val){
    Node * node = createNode(val);
    node->data = val;
    head = node;
    tail = NULL;
    return node;
}

Node * insertAtHead(int val){
    Node * tempNode;
    if(head == NULL){
        tempNode = init(val);
        tempNode->next = NULL;
        head = tempNode;
    }else{
        tempNode = createNode(val);
        tempNode->next = head;
        if(head->next == NULL){
            tail = head;
            tail->next = NULL;
        }
        head = tempNode;
    }
    return tempNode;
}

Node * insertAtTail(int val){
    Node * tempNode;

    if(head == NULL){
        tempNode = createNode(val);
        head = tempNode;
        return head;
    }else if(tail == NULL){
        tempNode = createNode(val);
        tempNode->next = NULL;
        head->next = tempNode;
        tail = tempNode;
        return tempNode;
    }else{
        tempNode = head;
        Node * tailNode = createNode(val);
        while(tempNode->next != NULL){
            tempNode = tempNode->next;
        }
        tail->next = tailNode;
        tail = tailNode;
        return tempNode;
    }
}void printLL(){
    Node * tempNode;
    tempNode = head;
    while(tempNode->next != NULL){
        printf("%d ->",tempNode->data);
        tempNode = tempNode->next;
    }
    printf("%d -> \n",tempNode->data);
}


Node * insertInMiddle(int val,int pos){
    Node * middleNode = createNode(val);
    if(head == NULL || tail == NULL){
        printf("No ELement in LL to insert between");
        return NULL;
    }else{
        Node * tempNode;
        tempNode = head;
        while(tempNode->next->data != pos){
            tempNode = tempNode->next;
        }
        middleNode->next = tempNode->next;
        tempNode->next = middleNode;
        return middleNode;
    }
}


Node * deleteHead(){
Node * tempNode;
    if(head==NULL){
        printf("LL is Empty");
        return NULL;
    }else{
        tempNode = head;
        head = head->next;
        free(tempNode);
        return head;
    }
}

Node * deleteTail(){
    Node * tempNode;
    if(tail == NULL && head==NULL){
        return NULL;
    }else if (tail == NULL)
    {
        deleteHead();
    }else{
        tempNode = head;
        while(tempNode->next->next != NULL){
            tempNode = tempNode->next;
        }
        if(tempNode == tail){
            tail = NULL;
        }else{
            free(tail);
            tail = tempNode;
   
        }
        tempNode->next = NULL;
        }
}

Node * deleteFromAnyWhere(int data){
    Node * tempNode = head;
    Node * todelete;
    while(tempNode->next->data != data){
        tempNode = tempNode->next;
    }
    todelete = tempNode->next;
    
    tempNode->next = tempNode->next->next;
    free(todelete);
}