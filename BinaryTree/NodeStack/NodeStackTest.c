#include"NodeStack.h"

int main(){
    struct Nodestack * nodeStack = init(5);

    BTNode ** btNode = (BTNode **)malloc(sizeof(BTNode)* 5);

    for (int i = 0; i <= 6; ++i) {
        btNode[i] = (BTNode *)malloc(sizeof(BTNode));
        btNode[i]->Value = i;
        push(nodeStack,btNode[i]);
    }

    printf("\n%d\n",pop(nodeStack)->Value);
    printf("\n%d\n",pop(nodeStack)->Value);
    printf("\n%d\n",pop(nodeStack)->Value);
    printf("\n%d\n",pop(nodeStack)->Value);
    printf("\n%d\n",pop(nodeStack)->Value);
    printf("\n%d\n",pop(nodeStack)->Value);
}