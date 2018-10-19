#include"LinkedList.h"

int main(){
    Node  * node = insertAtTail(6);
    insertAtTail(5);
    printLL();
    insertInMiddle(8,5);
    printLL();
    deleteHead();
    printLL();
    deleteHead();
    printLL();
    deleteHead();
    printLL();
    deleteHead();
    insertAtTail(7);
    insertAtTail(4);
    insertAtTail(2);
printLL();
deleteTail();
printLL();
    insertAtTail(21);
    insertAtTail(174);
    insertAtTail(85);
    insertAtTail(66);
printLL();
deleteFromAnyWhere(21);
printLL();

    deleteTail();
printLL();
    deleteTail();
printLL();
    deleteTail();
printLL();
    deleteTail();
printLL();
    deleteTail();
printLL();
    deleteTail();
printLL();

}