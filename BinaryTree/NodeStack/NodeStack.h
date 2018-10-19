#include"../BinaryTree.h"

typedef struct Nodestack{
    BTNode ** stackArr;
    int tos;
    int numOfElem;
}NodeStack;

struct NodeStack * init(int numOfElem);
bool push(struct Nodestack * nodeStack,BTNode * node);
BTNode * pop(struct Nodestack *nodeStack);
BTNode * peek(struct Nodestack * nodeStack);
bool isEmpty(struct Nodestack * nodeStack);