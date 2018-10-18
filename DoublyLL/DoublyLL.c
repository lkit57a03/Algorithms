#include"DoublyLL.h"

Node * createNode(int val){
    Node * node = (Node *)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    node->previous = NULL;
    return node;
}

Node * init(int val){
    Node * tempNode = createNode(val);
    head = tempNode;
    tail = NULL;
    return head;
}

Node * insertAtHead(int val){
    Node * tempNode = createNode(val);    
    if(head == NULL) return init(val);
    else{
        tempNode->next = head;
        if(tail == NULL){
            tail = head;
        }
        head->previous = tempNode;
        head = tempNode;
        return head;
    }
}

Node * insertAtTail(int val){
    Node * tempNode = createNode(val);    
    if(head == NULL) return init(val);
    else{
        if(tail == NULL){
            tail = tempNode;
            tempNode->previous = head;
            head->next = tempNode;
        }else{
            tempNode->previous = tail;
            tail->next = tempNode;
            tail = tempNode;
        }
    }    
}

Node * insertInMiddle(int val,int pos){
    Node * tempNode = head;    
    if(head == NULL || tail == NULL){
        printf("No ELement in LL to insert between");
        return NULL;
    }else{
        Node * tailNode = createNode(val);
        
        while(tempNode->data != pos){
            tempNode = tempNode->next;
        }
        tempNode->previous->next = tailNode;
        tailNode->next           = tempNode;
    }
}

Node * deleteHead(){
    if(head != NULL){
        Node * tempNode = head;
        if(head->next == NULL){
            free(head);
            return NULL;
        }
        head = head->next;
        head->previous = NULL;
        free(tempNode);
    }
}

Node * deleteTail(){
    if(head != NULL){
        if(tail == NULL){
            free(head);
        }else{
            Node * tempNode = tail;
            tail->previous->next = NULL;
            tail = tail->previous;
            free(tempNode);
        }
    }
}

Node * deleteFromAnyWhere(int data){
    Node * tempNode = head;     
    Node * toDelete;
    while(tempNode->data != data){
        tempNode = tempNode->next;        
    }
    toDelete = tempNode;
    tempNode->previous->next = tempNode->next;
    free(toDelete);
}

void printLL(){
    Node * tempNode;
    tempNode = head;
    while(tempNode->next != NULL){
        printf("%d ->",tempNode->data);
        tempNode = tempNode->next;
    }
    printf("%d -> \n",tempNode->data);
}