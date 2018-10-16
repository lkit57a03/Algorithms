#include "../Utility/Utility.h"
typedef struct stack {
    int * stackArr;
    int tos;
    int numOfElem;
}Stack;

Stack * init(Stack * stack,int numOfElem);
bool push(Stack * stack,int val);
int pop(Stack * stack);
int peek(Stack * stack);
bool isEmpty(Stack * stack);