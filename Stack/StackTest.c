// Stack using array, also show overflow and underflow in respective push and pop operations
#include"Stack.h"

int main(){
    Stack * stack = malloc(sizeof(Stack));
    init(stack,50);
    push(stack,50);
    push(stack,250);
    push(stack,150);
    push(stack,850);

    printf("%d",pop(stack));
}
