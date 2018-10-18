#include"../Utility/Utility.h"

typedef struct Node{
    int data;
    struct Node * next;
    struct Node * previous;
}Node;

Node * head;
Node * tail;

Node * createNode(int val);

Node * init(int val);

Node * insertAtHead(int val);

Node * insertAtTail(int val);

Node * insertInMiddle(int val,int pos);

Node * deleteHead();

Node * deleteTail();

Node * deleteFromAnyWhere(int data);

void printLL();