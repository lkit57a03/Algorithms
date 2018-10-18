#include "../LinkedList/LinkedList.h"

int numberOfELem(){
    int size = 0;
    Node * temp = head;
    while(temp->next != NULL){
        temp = temp->next;
        size++;
    }
    return ++size;
}
int main(){
    Node * node = LLinit(9);
    insertAtHead(8);
    insertAtHead(7);
    insertAtHead(6);
    insertAtHead(5);
    printLL();
    printf("\nThere are %d Elem in LL\n",numberOfELem());
}