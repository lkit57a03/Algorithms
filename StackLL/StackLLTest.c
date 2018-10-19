#include"StackLL.h"
int main(){
    Stack * stack = initStack(5);
    push(8);
    push(18);
    printf("\n%d\n",pop());
    printf("\n%d\n",pop());
    printf("\n%d\n",pop());
    printf("\n%d\n",pop());
    printf("\n%d\n",pop());
}