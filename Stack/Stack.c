#include"Stack.h"


Stack * init(Stack * stack,int numOfElem){
    stack->stackArr = (int *)malloc(numOfElem * sizeof(int));
    stack->tos = -1;
    stack->numOfElem = numOfElem;
}

bool push(Stack * stack,int val){
    if(stack->tos == stack->numOfElem){
        printAllElem(stack->stackArr,stack->numOfElem);
        printf("OverFlowCondition");
        return false;
    }else {
        stack->tos += 1;
        stack->stackArr[stack->tos] = val;
        return true;
    }
}

int pop(Stack * stack){
    if(stack->tos == -1){
        printf("StackIsEmpty");
        return 0;
    }else{
        stack->tos--;
        return stack->stackArr[stack->tos + 1];
    }
}

int peek(Stack * stack){
    if(stack->tos == -1){
        printf("StackIsEmpty");
        return 0;
    }else{
        return stack->stackArr[stack->tos];
    }
}

bool isEmpty(Stack * stack){
    if(stack->tos = -1){
        return true;
    }else{
        return false;
    }
}