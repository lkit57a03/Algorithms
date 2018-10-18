#include "../LinkedList/LinkedList.h"

void addToEveryNode(){
    Node * temp = head;
    while(temp != NULL){
        temp->data = temp->data + 10;
        temp = temp->next;
    }
}
int main(){
    Node * node = LLinit(9);
    insertAtHead(8);
    insertAtHead(7);
    insertAtHead(6);
    insertAtHead(5);
    printLL();
    addToEveryNode();
    printLL();
}