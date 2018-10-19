#include"NodeStack.h"

struct NodeStack * init(int numOfElem){
    struct Nodestack * nodeStack = (struct Nodestack *)malloc(sizeof(struct Nodestack));
    nodeStack->stackArr = (BTNode **)malloc(sizeof(BTNode *) * numOfElem);
    nodeStack->tos      = -1;
    nodeStack->numOfElem = numOfElem;
    return nodeStack;
}

bool push(struct Nodestack * nodeStack,BTNode * node){
    if(nodeStack->tos == nodeStack->numOfElem){
        printf("The Stack is Full");
    }else{
        nodeStack->tos += 1;
        nodeStack->stackArr[nodeStack->tos] = node;
        return true;
    }
}

BTNode * pop(struct Nodestack *nodeStack){
    if(nodeStack->tos == -1){
        printf("\nStack is Empty\n");
        return NULL;
    }else{
        nodeStack->tos -= 1;
        return nodeStack->stackArr[nodeStack->tos + 1];
    }
}

BTNode * peek(struct Nodestack * nodeStack){
    if(nodeStack->tos == -1){
        printf("\nStack is Empty\n");
        return NULL;
    }else{
        return nodeStack->stackArr[nodeStack->tos];
    }
}
bool isFull(struct Nodestack * nodeStack){
    return nodeStack->tos == nodeStack->numOfElem;
}

bool isEmpty(struct Nodestack * nodeStack){
    return nodeStack->tos == -1;
}